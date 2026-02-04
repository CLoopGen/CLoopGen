#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t int_simd16_t;

extern  int16_t FIX_0_382683433;
extern  int16_t FIX_0_541196100;
extern  int16_t FIX_0_707106781;
extern  int16_t FIX_1_306562965;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int cnt;
extern int_simd16_t tmp0;
extern int_simd16_t tmp1;
extern int_simd16_t tmp2;
extern int_simd16_t tmp3;
extern int_simd16_t tmp4;
extern int_simd16_t tmp5;
extern int_simd16_t tmp6;
extern int_simd16_t tmp7;
extern int_simd16_t tmp10;
extern int_simd16_t tmp11;
extern int_simd16_t tmp12;
extern int_simd16_t tmp13;
extern int_simd16_t z1;
extern int_simd16_t z2;
extern int_simd16_t z3;
extern int_simd16_t z4;
extern int_simd16_t z5;
extern int_simd16_t z11;
extern int_simd16_t z13;
extern int16_t *dataptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; cnt > 0; cnt--) {
    tmp0 = pixels[line_size * 0] + pixels[line_size * 7];
    tmp7 = pixels[line_size * 0] - pixels[line_size * 7];
    tmp1 = pixels[line_size * 1] + pixels[line_size * 6];
    tmp6 = pixels[line_size * 1] - pixels[line_size * 6];
    tmp2 = pixels[line_size * 2] + pixels[line_size * 5];
    tmp5 = pixels[line_size * 2] - pixels[line_size * 5];
    tmp3 = pixels[line_size * 3] + pixels[line_size * 4];
    tmp4 = pixels[line_size * 3] - pixels[line_size * 4];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    dataptr[2] = tmp10 + tmp11;
    dataptr[3] = tmp10 - tmp11;
    z1 = ((((tmp12 + tmp13) << 2) * (FIX_0_707106781)) >> 16);
    dataptr[0] = tmp13 + z1;
    dataptr[1] = tmp13 - z1;

    // Introduce artificial dependency: make tmp10 depend on previous iteration's z1 via loop-carried reuse
    static int_simd16_t prev_z1 = 0;
    tmp10 = ((tmp4 + tmp5) << 2) + (prev_z1 & 0xFFFF); // RAW dependency from prior iteration

    tmp11 = (tmp5 + tmp6) << 2;
    tmp12 = (tmp6 + tmp7) << 2;
    z5 = (((tmp10 - tmp12) * (FIX_0_382683433)) >> 16);
    z2 = (((tmp10) * (FIX_0_541196100)) >> 16) + z5;
    z4 = (((tmp12) * (FIX_1_306562965)) >> 16) + z5;
    z3 = (((tmp11) * (FIX_0_707106781)) >> 16);
    z11 = tmp7 + z3;
    z13 = tmp7 - z3;
    dataptr[4] = z13 + z2;
    dataptr[5] = z13 - z2;
    dataptr[6] = z11 + z4;
    dataptr[7] = z11 - z4;

    // Update state for next iteration (creates WAW and WAR hazard avoidance through ordering)
    prev_z1 = z1;

    pixels++;
    dataptr += 8;
}
}
