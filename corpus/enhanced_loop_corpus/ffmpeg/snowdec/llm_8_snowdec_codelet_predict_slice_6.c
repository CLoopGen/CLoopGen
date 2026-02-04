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
    for (x = 0; x < w; x += 2) {
        int v1 = buf[x + y * w] + (128 << 4) + (1 << 3);
        v1 >>= 4;
        if (v1 & (~255))
            v1 = ~(v1 >> 31);
        dst8[x + y * ref_stride] = v1;

        if (x + 1 < w) {
            int v2 = buf[(x + 1) + y * w] + (128 << 4) + (1 << 3);
            v2 >>= 4;
            if (v2 & (~255))
                v2 = ~(v2 >> 31);
            dst8[(x + 1) + y * ref_stride] = v2;
        }
    }
}
}
