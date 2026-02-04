#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern int stride;
extern int pos;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with flattened indexing
    int idx = pos;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            int flat_idx = idx + i;
            if (flat_idx < 0 || flat_idx >= height * stride)
                dst[i] = 0;
            else
                dst[i] = src[flat_idx];
        }
        dst += stride;
        src += stride;
        idx += stride;
    }
}
