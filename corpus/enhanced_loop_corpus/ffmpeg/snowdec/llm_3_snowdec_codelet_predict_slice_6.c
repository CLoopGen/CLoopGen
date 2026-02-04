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
IDWTELEM *local_buf = buf;
uint8_t *local_dst8 = dst8;
int stride_diff = ref_stride - w;
for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
    for (x = 0; x < w; x++) {
        int v = *local_buf++ + (128 << 4) + (1 << (4 - 1));
        v >>= 4;
        if (v & (~255))
            v = ~(v >> 31);
        *local_dst8++ = v;
    }
    local_dst8 += stride_diff;
}
}
