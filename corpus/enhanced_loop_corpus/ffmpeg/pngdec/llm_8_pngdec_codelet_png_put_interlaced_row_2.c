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
    int j2_a = 2 * (x & 3);
    int j2_b = 2 * ((x + 1) & 3);
    j = (x & 7);
    int j_next = ((x + 1) & 7);
    
    if ((dsp_mask << j) & 128) {
        b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
        dst[x >> 2] &= 65343 >> j2_a;
        dst[x >> 2] |= b << (6 - j2_a);
    }
    if ((mask << j) & 128)
        src_x++;

    if (x + 1 < width && ((dsp_mask << j_next) & 128)) {
        b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
        dst[(x + 1) >> 2] &= 65343 >> j2_b;
        dst[(x + 1) >> 2] |= b << (6 - j2_b);
    }
    if (x + 1 < width && ((mask << j_next) & 128))
        src_x++;
}
}
