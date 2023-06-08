#include "packet.h"

Packet create_packet(Segment seg){
    Packet packet;
    packet.segment = seg;
    packet.header.version = 4;
    packet.header.ihl = 5;
    packet.header.tos = 0;
    packet.header.tot_len = sizeof(packet.header);
    packet.header.id = 0;
    packet.header.frag_off = 0;
    packet.header.ttl = 0;
    packet.header.protocol = 0;
    packet.header.check = 0;
    packet.header.saddr = 100;
    packet.header.daddr = 200;

    // printf("checkpoint 3: %s\n", packet.segment->data->filedata);
    return packet;
};