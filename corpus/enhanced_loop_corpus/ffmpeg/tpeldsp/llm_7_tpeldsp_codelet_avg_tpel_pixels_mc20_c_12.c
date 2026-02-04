#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_dst_j = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint8_t computed_val = (((src[j] + 2 * src[j + 1] + 1) * 683) >> 11);
            dst[j] = (prev_dst_j + computed_val + 1) >> 1;
            prev_dst_j = dst[j];
        }
        src += stride;
        dst += stride;
        prev_dst_j = 0;
    }
}
