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
    for (i = 0; i < ((size) > (4) ? (4) : (size)); i += 2) {
        c->low = (c->low << 8) | *c->src++;
        if (i + 1 < ((size) > (4) ? (4) : (size)))
            c->low = (c->low << 8) | *c->src++;
    }
}
