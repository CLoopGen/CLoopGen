#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t int_simd16_t;

extern  int16_t FIX_1_414213562_A;
extern  int16_t FIX_1_847759065;
extern  int16_t FIX_2_613125930;
extern  int16_t FIX_1_414213562;
extern  int16_t FIX_1_082392200;
extern ptrdiff_t output_stride;
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
extern int_simd16_t z5;
extern int_simd16_t z10;
extern int_simd16_t z11;
extern int_simd16_t z12;
extern int_simd16_t z13;
extern int16_t *outptr;
extern int16_t *wsptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; cnt > 0; cnt--) {
    int_simd16_t local_tmp[8];
    int_simd16_t local_z[4];

    local_tmp[0] = wsptr[0]; local_tmp[1] = wsptr[1];
    local_tmp[2] = wsptr[2]; local_tmp[3] = wsptr[3];
    local_tmp[4] = wsptr[4]; local_tmp[5] = wsptr[5];
    local_tmp[6] = wsptr[6]; local_tmp[7] = wsptr[7];

    tmp13 = local_tmp[0] + local_tmp[1];
    tmp10 = local_tmp[2] + local_tmp[3];
    tmp11 = local_tmp[2] - local_tmp[3];
    tmp12 = ((((local_tmp[0] - local_tmp[1]) * FIX_1_414213562_A) >> 16) << 2) - tmp13;

    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    z13 = local_tmp[4] + local_tmp[5];
    z10 = local_tmp[4] - local_tmp[5];
    z11 = local_tmp[6] + local_tmp[7];
    z12 = local_tmp[6] - local_tmp[7];

    tmp7 = z11 + z13;
    tmp11 = (((z11 - z13) * FIX_1_414213562) >> 16);
    z5 = (((z10 + z12) * FIX_1_847759065) >> 16);

    tmp10 = (((z12 * FIX_1_082392200) >> 16)) - z5;
    tmp12 = (((z10 * FIX_2_613125930) >> 16)) + z5;

    tmp6 = (tmp12 << 3) - tmp7;
    tmp5 = (tmp11 << 3) - tmp6;
    tmp4 = (tmp10 << 3) + tmp5;

    int_simd16_t offset_val = (1 << 2);

    outptr[0 * output_stride] = (int16_t)((tmp0 + tmp7 + offset_val) >> 3);
    outptr[1 * output_stride] = (int16_t)((tmp1 + tmp6 + offset_val) >> 3);
    outptr[2 * output_stride] = (int16_t)((tmp2 + tmp5 + offset_val) >> 3);
    outptr[3 * output_stride] = (int16_t)((tmp3 - tmp4 + offset_val) >> 3);
    outptr[4 * output_stride] = (int16_t)((tmp3 + tmp4 + offset_val) >> 3);
    outptr[5 * output_stride] = (int16_t)((tmp2 - tmp5 + offset_val) >> 3);
    outptr[6 * output_stride] = (int16_t)((tmp1 - tmp6 + offset_val) >> 3);
    outptr[7 * output_stride] = (int16_t)((tmp0 - tmp7 + offset_val) >> 3);

    outptr += output_stride;
    wsptr += 8;
}
}
