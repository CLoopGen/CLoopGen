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
    int idx00 = src_linestep * int_x + i + src_linesize * int_y;
    int idx01 = src_linestep * int_x1 + i + src_linesize * int_y;
    int idx10 = src_linestep * int_x + i + src_linesize * int_y1;
    int idx11 = src_linestep * int_x1 + i + src_linesize * int_y1;

    if (idx00 < 0 || idx01 < 0 || idx10 < 0 || idx11 < 0) continue;

    int s00 = (((const union unaligned_16 *)(&src[idx00]))->l);
    int s01 = (((const union unaligned_16 *)(&src[idx01]))->l);
    int s10 = (((const union unaligned_16 *)(&src[idx10]))->l);
    int s11 = (((const union unaligned_16 *)(&src[idx11]))->l);

    int s0, s1;
    if (frac_x > (1 << 15)) {
        s0 = frac_x * (s01 - s00) + ((1 << 16) * s00);
        s1 = frac_x * (s11 - s10) + ((1 << 16) * s10);
    } else {
        s0 = (((1 << 16) - frac_x) * s00 + frac_x * s01);
        s1 = (((1 << 16) - frac_x) * s10 + frac_x * s11);
    }

    uint32_t result = (((int64_t)((1 << 16) - frac_y) * s0 + (int64_t)frac_y * s1) >> 32);
    ((((union unaligned_16 *)(&dst_color[i]))->l) = (uint16_t)(result & 0xFFFF));
}
}
