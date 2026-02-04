#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_dst_val = 0;
    for (x = w - 1; (x + 1) & 7; x--) {
        uint8_t temp = src[(x >> 1)] ^ prev_dst_val;
        dst[x] = temp;
        prev_dst_val = temp;
    }
}
