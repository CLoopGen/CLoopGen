#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst_color;
extern  uint8_t *src;
extern int src_linesize;
extern int src_linestep;
extern int int_x;
extern int int_y;
extern int frac_x;
extern int frac_y;
extern int i;
extern int int_x1;
extern int int_y1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < src_linestep; i++) {
    int s00, s01, s10, s11;
    if (i % 2 == 0) {
        s00 = src[src_linestep * int_x + i + src_linesize * int_y];
        s01 = src[src_linestep * int_x1 + i + src_linesize * int_y];
        s10 = src[src_linestep * int_x + i + src_linesize * int_y1];
        s11 = src[src_linestep * int_x1 + i + src_linesize * int_y1];
    } else {
        s00 = src[src_linestep * int_x1 + i + src_linesize * int_y1];
        s01 = src[src_linestep * int_x + i + src_linesize * int_y];
        s10 = src[src_linestep * int_x1 + i + src_linesize * int_y];
        s11 = src[src_linestep * int_x + i + src_linesize * int_y1];
    }
    int s0 = (((1 << 16) - frac_x) * s00 + frac_x * s01 + (1 << 15)) >> 16;
    int s1 = (((1 << 16) - frac_x) * s10 + frac_x * s11 + (1 << 15)) >> 16;
    dst_color[i] = ((int64_t)((1 << 16) - frac_y) * s0 + (int64_t)frac_y * s1 + (1LL << 31)) >> 32;
}
}
