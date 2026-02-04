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
    for (i = 1; i <= 16; i++) {
        uint16_t missing_seq = next_seq + i;
        RTPPacket *current = pkt;
        int found = 0;
        int seq_equal = 0;

        for (; current != NULL && !found; current = current->next) {
            int16_t diff = current->seq - missing_seq;
            found = (diff >= 0);
            seq_equal = (current->seq == missing_seq);
        }

        if (!found) break;
        if (seq_equal) continue;
        *missing_mask |= 1 << (i - 1);
    }
}
