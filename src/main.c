#include <stdio.h>
#include <string.h>
#include <netinet/ether.h>

#include "frame.h"


Frame send_file(char *file, char *smac, char *dmac){


    char data[DATA_SIZE];
    char segment1[DATA_SIZE];
    char packet1[DATA_SIZE];
    char frame1[DATA_SIZE];

    // Application Layer for Sender
    create_data(file, data);
    printf("Application checkpoint: '%s'\n", data);


    // Transport Layer for Sender - TCP/UDP header
    create_segment(data, segment1);
    Segment seg;

    // Network Layer for Sender - IP header
    Packet packet = create_packet(seg);

    // Data Link Layer for Sender - MAC header
    Frame frame = create_data_frame(packet, smac, dmac);

    return frame;
};

char *receive_file(Frame frame, char *my_mac) {
    // Data Link Layer for receiver
    if (frame.header.dmac == my_mac) {
        printf("FRAME RECEIVED!\n");
    }

    // Network Layer for receiver
    Packet packet = frame.packet;

    // Transport Layer for receiver
    Segment seg = packet.segment;

    // Application Layer for receiver
    Data data = seg.data;

    // Data tmp;
    // string_to_data(buf, &tmp);

    char *filedata = data.filedata;

    return filedata;
};


int main(int argc, char const *argv[])
{
    char *file = "./src/test.txt";
    char *smac = "00:30:bd:26:70:7f", *dmac = "00:09:5b:56:5f:8b";

    Frame f = send_file(file, smac, dmac);
    char *data = receive_file(f, dmac);
    // printf(data);
    return 0;
}
