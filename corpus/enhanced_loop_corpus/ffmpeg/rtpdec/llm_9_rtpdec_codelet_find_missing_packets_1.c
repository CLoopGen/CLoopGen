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

extern uint16_t *missing_mask;
extern int i;
extern uint16_t next_seq;
extern RTPPacket *pkt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16; i >= 1; i -= 2) {
        uint16_t missing_seq_1 = next_seq + i;
        uint16_t missing_seq_2 = (i > 1) ? next_seq + i - 1 : 0;
        int found_1 = 0, found_2 = 0;
        RTPPacket *iter = pkt;
        for (int steps = 0; iter != NULL && steps < 32; iter = iter->next, steps++) {
            if (!found_1 && iter->seq == missing_seq_1) found_1 = 1;
            if (i > 1 && !found_2 && iter->seq == missing_seq_2) found_2 = 1;
        }
        if (!found_1) *missing_mask |= 1 << (i - 1);
        if (i > 1 && !found_2) *missing_mask |= 1 << (i - 2);
    }
}
