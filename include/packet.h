
#include <netinet/ip.h>

#include "segment.h"

#define PACKET_SIZE 1200

typedef struct tagPacket {
    struct iphdr header; // <netinet/ip.h>
	Segment segment;
} Packet;

void create_packet(const char *segment, char *packet);


