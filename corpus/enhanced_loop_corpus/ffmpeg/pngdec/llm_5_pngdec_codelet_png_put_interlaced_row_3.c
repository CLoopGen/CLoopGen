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
    int j2 = 4 * (x & 1);
    j = (x & 7);

    int dsp_cond = (dsp_mask << j) & 128;
    int mask_cond = (mask << j) & 128;

    if (!dsp_cond && !mask_cond) continue;

    if (dsp_cond) {
        b = (src[src_x >> 1] >> (4 - 4 * (src_x & 1))) & 15;
        dst[x >> 1] &= 65295 >> j2;
        dst[x >> 1] |= b << (4 - j2);
    }

    if (mask_cond)
        src_x++;
}
}
