#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int i;
extern  int32_t *src;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int32_t *src_offset = &src[i]; // Strided access: process one element at a time with stride of 1, but across iterations
    int16_t *out_offset = (int16_t *)((char *)out + i * pitch); // Indirect and strided output access via byte arithmetic

    if (!src_offset[0] && !src_offset[4] && !src_offset[8] && !src_offset[12]) { // Strided read pattern (every 4th element)
        out_offset[0] = out_offset[1] = out_offset[2] = out_offset[3] = 0;
    } else {
        t0 = (src_offset[0]) - (src_offset[8]);
        t1 = (src_offset[0]) + (src_offset[8]);
        t2 = (t0);
        ;
        t0 = (((src_offset[4]) + (src_offset[12]) * 2 + 2) >> 2) + (src_offset[4]);
        t3 = (((src_offset[4]) * 2 - (src_offset[12]) + 2) >> 2) - (src_offset[12]);
        t4 = (t0);
        ;
        t0 = (t1) - (t4);
        t1 = (t1) + (t4);
        t4 = (t0);
        ;
        t0 = (t2) - (t3);
        t2 = (t2) + (t3);
        t3 = (t0);
        ;
        out_offset[0] = (((t1) + 1) >> 1);
        out_offset[1] = (((t2) + 1) >> 1);
        out_offset[2] = (((t3) + 1) >> 1);
        out_offset[3] = (((t4) + 1) >> 1);
    }
}
}
