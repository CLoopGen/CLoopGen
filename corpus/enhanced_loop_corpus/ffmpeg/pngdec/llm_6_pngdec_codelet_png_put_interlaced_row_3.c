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
    int shifted_dsp_mask = dsp_mask << j;
    int shifted_mask = mask << j;
    if (shifted_dsp_mask & 128) {
        int src_index = src_x >> 1;
        int src_shift = 4 - 4 * (src_x & 1);
        b = (src[src_index] >> src_shift) & 15;
        int dst_index = x >> 1;
        dst[dst_index] &= 65295 >> j2;
        dst[dst_index] |= b << (4 - j2);
    }
    if (shifted_mask & 128)
        src_x++;
}
}
