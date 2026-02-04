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
    uint32_t temp_low = c->low;
    for (i = 0; i < ((size) > (4) ? (4) : (size)); i++) {
        temp_low = (temp_low << 8) | *c->src++;
    }
    c->low = temp_low;
}
