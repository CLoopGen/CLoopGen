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
    for (x = 0; x < w - 7; x += 8) {
        for (int k = 0; k < 4; ++k) {
            int src_idx = (x >> 1) + k;
            int dst_base = x + (k << 1);
            dst[dst_base + 0] = src[src_idx];
            dst[dst_base + 1] = src[src_idx];
        }
    }
}
