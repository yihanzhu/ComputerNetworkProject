#include "frame.h"

Frame create_data_frame(Packet packet, char *smac, char *dmac) {
    Frame frame;
    frame.packet = packet;
    frame.header.smac = smac;
    frame.header.dmac = dmac;
    frame.header.ether_type = htons(ETH_P_IP);

    // printf("checkpoint 4: %s\n", frame.packet->segment->data->filedata);
    // printf("checkpoint 5: %s\n", frame.header.smac);

    // struct ether_addr *source, *dest;
    // source = ether_aton(smac);
    // dest = ether_aton(dmac);
    // bcopy(source->ether_addr_octet, frame.header.ether_shost, ETH_ALEN);
    // bcopy(dest->ether_addr_octet, frame.header.ether_dhost, ETH_ALEN);

    char datagram[4096];
    memset(datagram, 0, 4096);
    // Data Link Layer for Sender - MAC header
    struct ether_header *ethh = (struct ether_header *) datagram;
    // Network Layer for Sender - IP header
    struct iphdr *iph = (struct iphdr *) datagram;
    // Transport Layer for Sender - UDP header
    struct udphdr *udph = (struct udphdr *) (datagram + sizeof(struct iphdr));
    //Data part
    char *data = (char *) (datagram + sizeof(struct iphdr) + sizeof(struct udphdr));
    strcpy(data , "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return frame;
}