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
    for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
        for (int yy = y * w, dy = y * ref_stride; yy < (y + 1) * w; yy++, dy++) {
            int v = buf[yy] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[dy] = v;
        }
    }
}
