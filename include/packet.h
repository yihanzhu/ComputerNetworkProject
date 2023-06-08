
#include <netinet/ip.h>

#include "segment.h"

typedef struct tagPacket {
    struct iphdr header; // <netinet/ip.h>
	Segment segment;
} Packet;

Packet create_packet(Segment seg);


