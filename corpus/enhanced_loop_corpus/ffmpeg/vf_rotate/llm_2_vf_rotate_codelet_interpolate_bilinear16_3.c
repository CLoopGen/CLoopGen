#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


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
    // Variant 1: Consecutive Memory Access with Prefetched Indices
    // Instead of recalculating base addresses repeatedly, precompute row pointers and access consecutively.
    uint8_t *src_base0 = &src[src_linesize * int_y];
    uint8_t *src_base1 = &src[src_linesize * int_y1];
    uint8_t *dst = dst_color;
    int fx = frac_x;
    int fy = frac_y;
    int ifx = (1 << 16) - fx;
    int ify = (1 << 16) - fy;
    int x_step = src_linestep * int_x;
    int x1_step = src_linestep * int_x1;

    for (int i = 0; i < src_linestep; i += 2) {
        const union unaligned_16 *s00_ptr = (const void*)(src_base0 + x_step + i);
        const union unaligned_16 *s01_ptr = (const void*)(src_base0 + x1_step + i);
        const union unaligned_16 *s10_ptr = (const void*)(src_base1 + x_step + i);
        const union unaligned_16 *s11_ptr = (const void*)(src_base1 + x1_step + i);

        int s00 = s00_ptr->l;
        int s01 = s01_ptr->l;
        int s10 = s10_ptr->l;
        int s11 = s11_ptr->l;

        int s0 = ifx * s00 + fx * s01;
        int s1 = ifx * s10 + fx * s11;

        ((union unaligned_16 *)(dst + i))->l = (uint16_t)(((int64_t)ify * s0 + (int64_t)fy * s1) >> 32);
    }
}
