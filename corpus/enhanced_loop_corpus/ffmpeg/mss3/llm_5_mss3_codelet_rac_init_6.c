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
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((size > 0 && size < 4) ? size : 4); i++) {
        uint8_t input = *(c->src);
        c->src++;
        c->low = (c->low << 8) | input;
        if (c->range == 0) {
            c->low ^= 0xFFFFFFFF;
        }
    }
}
