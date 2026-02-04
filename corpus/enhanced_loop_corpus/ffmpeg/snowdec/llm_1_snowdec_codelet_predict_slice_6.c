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
    int total_elements = (y_end - y_start) * w;

    for (int idx = 0; idx < total_elements; idx++) {
        y = y_start + idx / w;
        x = idx % w;
        int v = buf[x + y * w] + (128 << 4) + (1 << (4 - 1));
        v >>= 4;
        if (v & (~255))
            v = ~(v >> 31);
        dst8[x + y * ref_stride] = v;
    }
}
