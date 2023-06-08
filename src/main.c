#include <stdio.h>
#include <string.h>
#include <netinet/ether.h>

#include "frame.h"


void send_file(const char *file, char *frame){

    char data[DATA_SIZE];
    char segment[SEG_SIZE];
    char packet[PACKET_SIZE];

    // Application Layer for Sender
    create_data(file, data);

    // Transport Layer for Sender - TCP/UDP header
    create_segment(data, segment);

    // Network Layer for Sender - IP header
    create_packet(segment, packet);

    // Data Link Layer for Sender - MAC header
    create_frame(packet, frame);

};

char *receive_file(const char *frame, char *message) {

};


int main(int argc, char const *argv[])
{
    char *file = "./src/test.txt";
    char datagram[4096];
    char *message = "";

    send_file(file, datagram);
    printf("%s: %s\n", __func__, datagram+sizeof (struct udphdr)+sizeof(struct iphdr)+sizeof(struct ether_header));

    receive_file(datagram, message);
    printf("%s: %s\n", __func__, message);
    return 0;
}
