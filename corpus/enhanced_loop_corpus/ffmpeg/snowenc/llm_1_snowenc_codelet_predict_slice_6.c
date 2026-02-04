#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int ref_stride;
extern uint8_t *dst8;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start_y = block_h * mb_y;
    int end_y = (h > (block_h * (mb_y + 1))) ? (block_h * (mb_y + 1)) : h;
    for (y = start_y; y < end_y; y++) {
        for (x = 0; x < w; x++) {
            int v = buf[x + y * w] + (128 << 4) + (1 << 3);
            v = (v + 8) >> 4;  // Equivalent arithmetic with rounding
            if (v > 255)
                v = 255;
            else if (v < 0)
                v = 0;
            dst8[x + y * ref_stride] = (uint8_t)v;
        }
    }
}
