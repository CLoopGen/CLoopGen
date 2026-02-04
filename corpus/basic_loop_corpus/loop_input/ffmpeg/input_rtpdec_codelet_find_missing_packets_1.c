#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RTPPacket {
    uint16_t seq;
    uint8_t *buf;
    int len;
    int64_t recvtime;
    struct RTPPacket *next;
} RTPPacket;

uint16_t *missing_mask;
int i;
uint16_t next_seq;
RTPPacket *pkt;

static uint16_t missing_mask_storage;
static RTPPacket* packet_array;
static int num_packets = 65536;

void init_vars() {
    // Allocate and initialize missing_mask
    missing_mask = &missing_mask_storage;
    missing_mask_storage = 0;

    // Initialize loop counter
    i = 0;

    // Initialize base sequence number
    next_seq = 1000;

    // Allocate packet array
    packet_array = (RTPPacket*)calloc(num_packets, sizeof(RTPPacket));
    if (!packet_array) exit(1);

    // Initialize packet sequence numbers in increasing order
    for (int j = 0; j < num_packets; j++) {
        packet_array[j].seq = next_seq + j + 1;  // Start after next_seq
        packet_array[j].buf = NULL;
        packet_array[j].len = 0;
        packet_array[j].recvtime = j * 1000LL;
        if (j < num_packets - 1) {
            packet_array[j].next = &packet_array[j + 1];
        } else {
            packet_array[j].next = NULL;
        }
    }

    // Set initial pkt pointer to first packet
    pkt = &packet_array[0];
}