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
for (i = 0; i < src_linestep; i += 4) {
    int s00_0 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + src_linesize * int_y]))->l);
    int s01_0 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + src_linesize * int_y]))->l);
    int s10_0 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + src_linesize * int_y1]))->l);
    int s11_0 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + src_linesize * int_y1]))->l);
    int s0_0 = (((1 << 16) - frac_x) * s00_0 + frac_x * s01_0);
    int s1_0 = (((1 << 16) - frac_x) * s10_0 + frac_x * s11_0);
    ((((union unaligned_16 *)(&dst_color[i]))->l) = (((int64_t)((1 << 16) - frac_y) * s0_0 + (int64_t)frac_y * s1_0) >> 32));

    if (i + 2 < src_linestep) {
        int s00_1 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + 2 + src_linesize * int_y]))->l);
        int s01_1 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + 2 + src_linesize * int_y]))->l);
        int s10_1 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + 2 + src_linesize * int_y1]))->l);
        int s11_1 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + 2 + src_linesize * int_y1]))->l);
        int s0_1 = (((1 << 16) - frac_x) * s00_1 + frac_x * s01_1);
        int s1_1 = (((1 << 16) - frac_x) * s10_1 + frac_x * s11_1);
        ((((union unaligned_16 *)(&dst_color[i + 2]))->l) = (((int64_t)((1 << 16) - frac_y) * s0_1 + (int64_t)frac_y * s1_1) >> 32));
    }
}
}
