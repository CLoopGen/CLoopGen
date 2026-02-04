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
    for (int outer = 0; outer < (width + 7) / 8; outer++) {
        for (int inner = 0; inner < 8; inner++) {
            x = outer * 8 + inner;
            if (x >= width) break;
            j = (x & 7);
            if ((dsp_mask << j) & 128) {
                b = (src[src_x >> 3] >> (7 - (src_x & 7))) & 1;
                dst[x >> 3] &= 65407 >> j;
                dst[x >> 3] |= b << (7 - j);
            }
            if ((mask << j) & 128)
                src_x++;
        }
    }
}
