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
for (i = 0; i < src_linestep; i += 2) {
    if (!(src_linestep * int_x + i + src_linesize * int_y & 1) && !(src_linestep * int_x1 + i + src_linesize * int_y & 1)) {
        int s00 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + src_linesize * int_y]))->l);
        int s01 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + src_linesize * int_y]))->l);
        int s10 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + src_linesize * int_y1]))->l);
        int s11 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + src_linesize * int_y1]))->l);
        int s0 = (((1 << 16) - frac_x) * s00 + frac_x * s01);
        int s1 = (((1 << 16) - frac_x) * s10 + frac_x * s11);
        ((((union unaligned_16 *)(&dst_color[i]))->l) = (((int64_t)((1 << 16) - frac_y) * s0 + (int64_t)frac_y * s1) >> 32));
    } else {
        int base_idx0 = src_linestep * int_x + i + src_linesize * int_y;
        int base_idx1 = src_linestep * int_x1 + i + src_linesize * int_y;
        uint16_t fallback_val = 0;
        if (base_idx0 >= 0 && base_idx0 + 1 < src_linesize * (int_y + 1)) {
            fallback_val = (((const union unaligned_16 *)(&src[base_idx0]))->l);
        }
        ((((union unaligned_16 *)(&dst_color[i]))->l) = fallback_val);
    }
}
}
