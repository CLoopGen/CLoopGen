#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct RangeCoder {
    const uint8_t *src;
    const uint8_t *src_end;
    uint32_t range;
    uint32_t low;
    int got_error;
} RangeCoder;

extern RangeCoder *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t shift_amount = 8;
    uint32_t threshold = 16777216;
    uint32_t error_state = c->got_error;
    for (;;) {
        c->range <<= shift_amount;
        c->low <<= shift_amount;
        if (c->src < c->src_end) {
            c->low |= *c->src;
            c->src += 1;
        } else if (!(c->low & 0xFFFFFFFF)) {
            error_state = 1;
            c->low = 1;
        }
        if ((c->low ^ c->range) & 0x80000000) {
            error_state = 1;
            c->low = 1;
        }
        if (c->range >= threshold)
            break;
    }
    c->got_error = error_state;
    return;
}
