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
for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y += 2) {
    for (x = 0; x < w; x++) {
        int idx1 = x + y * w;
        int idx2 = x + (y + 1) * w;
        int v1 = (buf[idx1] + 2048 + 8) >> 4;
        v1 = (v1 > 255) ? 255 : (v1 < 0) ? 0 : v1;
        dst8[x + y * ref_stride] = v1;

        if (y + 1 < h) {
            int v2 = (buf[idx2] + 2048 + 8) >> 4;
            v2 = (v2 > 255) ? 255 : (v2 < 0) ? 0 : v2;
            dst8[x + (y + 1) * ref_stride] = v2;
        }
    }
}
}
