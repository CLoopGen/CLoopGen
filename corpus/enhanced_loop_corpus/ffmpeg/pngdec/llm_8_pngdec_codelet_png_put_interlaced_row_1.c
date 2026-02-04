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
for (x = 0; x < width; x += 2) {
    j = (x & 7);
    int shift_j1 = (dsp_mask << j) & 128;
    int shift_j2 = (mask << j) & 128;
    if (shift_j1) {
        b = (src[src_x >> 3] >> (7 - (src_x & 7))) & 1;
        dst[x >> 3] &= 65407 >> j;
        dst[x >> 3] |= b << (7 - j);
    }
    if (shift_j2)
        src_x++;
    if (x + 1 < width) {
        int j2 = ((x + 1) & 7);
        if ((dsp_mask << j2) & 128) {
            b = (src[src_x >> 3] >> (7 - (src_x & 7))) & 1;
            dst[(x + 1) >> 3] &= 65407 >> j2;
            dst[(x + 1) >> 3] |= b << (7 - j2);
        }
        if ((mask << j2) & 128)
            src_x++;
    }
}
}
