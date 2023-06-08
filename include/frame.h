
#include <net/ethernet.h>
#include "packet.h"

#define FRAME_SIZE 1300

typedef struct tagEthHeader {
    char *       dmac;
    char *       smac;
    uint16_t       ether_type;
} EthHeader;

typedef struct tagFrame {
    // struct ether_header header; // <net/ethernet.h>
	EthHeader header;
	Packet packet;
} Frame;

void create_frame(const char *packet, char *frame);