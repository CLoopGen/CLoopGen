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
    int y_start = block_h * mb_y;
    int y_end = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;
    for (y = y_start; y < y_end; y++) {
        int offset = y * w;
        int dst_offset = y * ref_stride;
        for (x = 0; x < w; x++) {
            int v = buf[x + offset] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[x + dst_offset] = v;
        }
    }
}
