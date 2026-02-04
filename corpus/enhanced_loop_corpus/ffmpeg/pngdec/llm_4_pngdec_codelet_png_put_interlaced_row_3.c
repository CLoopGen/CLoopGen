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
    int mask_shift = dsp_mask << j;
    int src_index = src_x >> 1;
    int src_shift = 4 - 4 * (src_x & 1);
    int dst_shift = 4 - j2;
    int dst_mask = 65295 >> j2;

    if ((mask_shift & 128)) {
        b = (src[src_index] >> src_shift) & 15;
        dst[x >> 1] = (dst[x >> 1] & dst_mask) | (b << dst_shift);
        src_x++;
    }
}
}
