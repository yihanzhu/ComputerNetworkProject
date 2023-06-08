#include "packet.h"

void create_packet(const char *segment, char *packet){

    memset(packet, 0, PACKET_SIZE);

    // Network Layer for Sender - IP header
    struct iphdr *iph = (struct iphdr *) packet;

    // segment part
    char *data = (char *) (packet + sizeof(struct iphdr));
    memcpy(data, segment, SEG_SIZE);

    // printf("%s: %d\n", __func__, strlen(data+sizeof (struct udphdr)));

    //Fill in the IP Header
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof (struct iphdr) + sizeof (struct udphdr) + strlen(data+sizeof (struct udphdr));
    iph->id = htonl(54321); //Id of this packet
    iph->frag_off = 0;
    iph->ttl = 255;
    iph->protocol = IPPROTO_UDP;
    iph->check = 0;      //Set to 0 before calculating checksum
    iph->saddr = inet_addr("192.168.1.2");    //Spoof the source ip address
    iph->daddr = inet_addr("192.168.1.1");

    // printf("%s: %s\n", __func__, packet + sizeof(struct iphdr)+4*sizeof(uint16_t));

    // Packet packet;
    // packet.segment = seg;
    // packet.header.version = 4;
    // packet.header.ihl = 5;
    // packet.header.tos = 0;
    // packet.header.tot_len = sizeof(packet.header);
    // packet.header.id = 0;
    // packet.header.frag_off = 0;
    // packet.header.ttl = 0;
    // packet.header.protocol = 0;
    // packet.header.check = 0;
    // packet.header.saddr = 100;
    // packet.header.daddr = 200;

    // // printf("checkpoint 3: %s\n", packet.segment->data->filedata);
    // return packet;
}