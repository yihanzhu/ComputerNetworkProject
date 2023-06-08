
#include <net/ethernet.h>
#include "packet.h"

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

Frame create_data_frame(Packet packet, char *smac, char *dmac);