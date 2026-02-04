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
    int s00 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + src_linesize * int_y]))->l);
    int s01 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + src_linesize * int_y]))->l);
    int s10 = (((const union unaligned_16 *)(&src[src_linestep * int_x + i + src_linesize * int_y1]))->l);
    int s11 = (((const union unaligned_16 *)(&src[src_linestep * int_x1 + i + src_linesize * int_y1]))->l);
    int s0 = (((1 << 16) - frac_x) * s00 + frac_x * s01 + s11) & 0xFFFFFFFF; // Added WAR dependency: s11 used before write in next line
    int s1 = (((1 << 16) - frac_x) * s10 + frac_x * s01); // Reused s01 to create additional RAW dependency
    ((((union unaligned_16 *)(&dst_color[i]))->l) = (((int64_t)((1 << 16) - frac_y) * s0 + (int64_t)frac_y * s1) >> 32));
}
}
