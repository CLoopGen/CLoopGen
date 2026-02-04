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
    uint32_t temp_low = c->low;
    uint32_t temp_range = c->range;
    for (;;) {
        temp_range <<= 8;
        temp_low <<= 8;
        if (c->src < c->src_end) {
            temp_low |= *c->src++;
        } else if (!temp_low) {
            c->got_error = 1;
            temp_low = 1;
        }
        if (temp_low > temp_range) {
            c->got_error = 1;
            temp_low = 1;
        }
        if (temp_range >= 16777216) {
            c->range = temp_range;
            c->low = temp_low;
            return;
        }
        c->range = temp_range;
        c->low = temp_low;
    }
}
