#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern  uint8_t *src;
extern int x;
extern int mask;
extern int dsp_mask;
extern int j;
extern int src_x;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x++) {
    j = (x & 7);
    int dsp_cond = (dsp_mask << j) & 128;
    int mask_cond = (mask << j) & 128;
    if (dsp_cond || mask_cond) {
        if (dsp_cond) {
            b = (src[src_x >> 3] >> (7 - (src_x & 7))) & 1;
            dst[x >> 3] &= 65407 >> j;
            dst[x >> 3] |= b << (7 - j);
        }
        if (mask_cond) {
            src_x++;
        }
    }
}
}
