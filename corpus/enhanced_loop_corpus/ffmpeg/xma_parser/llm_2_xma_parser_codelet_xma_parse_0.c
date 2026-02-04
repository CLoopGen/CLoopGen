#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct XMAParserContext {
    int skip_packets;
} XMAParserContext;

extern  uint8_t *buf;
extern XMAParserContext *s;
extern int duration;
extern int packet;
extern int nb_packets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled with stride simulation)
    // Instead of accessing buf[packet * 2048] and buf[packet * 2048 + 3], we precompute the base index
    // and access memory in a more cache-friendly manner by reducing multiplication per iteration.
    int idx = 0;
    for (packet = 0; packet < nb_packets; packet++) {
        if (s->skip_packets == 0) {
            duration += buf[idx] * 128;
            s->skip_packets = buf[idx + 3] + 1;
        }
        s->skip_packets--;
        idx += 2048; // Stride of 2048 bytes between packets
    }
}
