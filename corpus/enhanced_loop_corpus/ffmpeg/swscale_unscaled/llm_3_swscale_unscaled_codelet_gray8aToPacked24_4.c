#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_pixels; i++) {
        int src_offset = i * 2;
        int pidx = src[src_offset] * 4;
        *(dst++) = palette[pidx];
        *(dst++) = palette[pidx + 1];
        *(dst++) = palette[pidx + 2];
    }
}
