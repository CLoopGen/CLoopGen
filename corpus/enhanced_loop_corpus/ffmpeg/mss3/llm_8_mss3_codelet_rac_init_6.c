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
    int limit = (size > 8) ? 8 : size;
    for (i = 0; i < limit; i += 2) {
        c->low = (c->low << 16) | (*c->src++ << 8) | (*c->src++);
        if (++i >= limit) break;
    }
}
