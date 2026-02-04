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
    for (int shift = 0; shift < 24; shift += 8) {
        c->range <<= 8;
        c->low <<= 8;
        if (c->src < c->src_end) {
            c->low |= *c->src++;
        } else if (!c->low) {
            c->got_error = 1;
            c->low = 1;
        }
        if (c->low > c->range) {
            c->got_error = 1;
            c->low = 1;
        }
        if (c->range >= 16777216)
            return;
    }
}
