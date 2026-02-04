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
    int j2 = 2 * (x & 3);
    j = (x & 7);
    if (((dsp_mask << j) & 128) && ((mask << j) & 128)) {
        b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
        dst[x >> 2] &= 65343 >> j2;
        dst[x >> 2] |= b << (6 - j2);
        src_x++;
    } else if ((dsp_mask << j) & 128) {
        b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
        dst[x >> 2] &= 65343 >> j2;
        dst[x >> 2] |= b << (6 - j2);
    } else if ((mask << j) & 128) {
        src_x++;
    }
}
}
