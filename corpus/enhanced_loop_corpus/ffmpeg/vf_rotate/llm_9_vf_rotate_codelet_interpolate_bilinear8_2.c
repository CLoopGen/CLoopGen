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
    int trip_count = src_linestep >> 1;
    for (i = 0; i < trip_count; i++) {
        int idx = i << 1;
        int base0 = src_linestep * int_x + src_linesize * int_y;
        int base1 = src_linestep * int_x1 + src_linesize * int_y;
        int base2 = src_linestep * int_x + src_linesize * int_y1;
        int base3 = src_linestep * int_x1 + src_linesize * int_y1;

        int s00 = src[base0 + idx];
        int s01 = src[base1 + idx];
        int s10 = src[base2 + idx];
        int s11 = src[base3 + idx];

        int s0 = ((65536 - frac_x) * s00 + frac_x * s01 + (1 << 31)) >> 16;
        int s1 = ((65536 - frac_x) * s10 + frac_x * s11 + (1 << 31)) >> 16;

        int64_t val = ((int64_t)(65536 - frac_y) * s0 + (int64_t)frac_y * s1 + (1LL << 31)) >> 32;
        dst_color[idx] = (uint8_t)val;

        s00 = src[base0 + idx + 1];
        s01 = src[base1 + idx + 1];
        s10 = src[base2 + idx + 1];
        s11 = src[base3 + idx + 1];

        s0 = ((65536 - frac_x) * s00 + frac_x * s01 + (1 << 31)) >> 16;
        s1 = ((65536 - frac_x) * s10 + frac_x * s11 + (1 << 31)) >> 16;

        val = ((int64_t)(65536 - frac_y) * s0 + (int64_t)frac_y * s1 + (1LL << 31)) >> 32;
        dst_color[idx + 1] = (uint8_t)val;
    }
}
