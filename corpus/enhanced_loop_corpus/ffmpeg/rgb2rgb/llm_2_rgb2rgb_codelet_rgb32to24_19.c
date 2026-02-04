#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_pixels; i++) {
        int dst_idx = 3 * i;
        int src_idx = 4 * i;
        dst[dst_idx + 0] = src[src_idx + 2];
        dst[dst_idx + 1] = src[src_idx + 1];
        dst[dst_idx + 2] = src[src_idx + 0];
    }
}
