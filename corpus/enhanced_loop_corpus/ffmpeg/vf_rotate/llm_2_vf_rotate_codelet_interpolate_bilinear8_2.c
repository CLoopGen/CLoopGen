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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize memory accesses to be consecutive by precomputing base pointers and using linear indexing.
    uint8_t *base_y = &src[src_linesize * int_y];
    uint8_t *base_y1 = &src[src_linesize * int_y1];
    int weight_x_inv = (1 << 16) - frac_x;
    int weight_y_inv = (1 << 16) - frac_y;
    for (i = 0; i < src_linestep; i++) {
        int idx0 = src_linestep * int_x + i;
        int idx1 = src_linestep * int_x1 + i;
        int s00 = base_y[idx0];
        int s01 = base_y[idx1];
        int s10 = base_y1[idx0];
        int s11 = base_y1[idx1];
        int s0 = weight_x_inv * s00 + frac_x * s01;
        int s1 = weight_x_inv * s10 + frac_x * s11;
        dst_color[i] = ((int64_t)weight_y_inv * s0 + (int64_t)frac_y * s1) >> 32;
    }
}
