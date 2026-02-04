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
        for (; pkt && (int16_t)(pkt->seq - missing_seq) < 0; pkt = pkt->next)
            ;
        if (!pkt)
            break;
        if (pkt->seq == missing_seq)
            continue;
        *missing_mask |= 1 << (i - 1);
    }
}
