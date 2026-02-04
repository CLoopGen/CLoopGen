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



void loop() {
    for (; cnt > 0; cnt--) {
        int_simd16_t wsptr_vals[8];
        for (int i = 0; i < 8; i++) {
            wsptr_vals[i] = wsptr[i];
        }

        tmp10 = wsptr_vals[2] + wsptr_vals[3];
        tmp11 = wsptr_vals[2] - wsptr_vals[3];
        tmp13 = wsptr_vals[0] + wsptr_vals[1];
        tmp12 = ((((wsptr_vals[0] - wsptr_vals[1]) * FIX_1_414213562_A) >> 16) << 2) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = wsptr_vals[4] + wsptr_vals[5];
        z10 = wsptr_vals[4] - wsptr_vals[5];
        z11 = wsptr_vals[6] + wsptr_vals[7];
        z12 = wsptr_vals[6] - wsptr_vals[7];
        tmp7 = z11 + z13;
        tmp11 = (((z11 - z13) * FIX_1_414213562) >> 16);
        z5 = (((z10 + z12) * FIX_1_847759065) >> 16);
        tmp10 = (((z12) * FIX_1_082392200) >> 16) - z5;
        tmp12 = (((z10) * FIX_2_613125930) >> 16) + z5;
        tmp6 = (tmp12 << 3) - tmp7;
        tmp5 = (tmp11 << 3) - tmp6;
        tmp4 = (tmp10 << 3) + tmp5;

        int16_t out_vals[8];
        for (int i = 0; i < 8; i++) {
            out_vals[i] = outptr[i * output_stride];
        }

        out_vals[0] += (((tmp0 + tmp7) + (1 << ((3) - 1))) >> 3);
        out_vals[1] += (((tmp1 + tmp6) + (1 << ((3) - 1))) >> 3);
        out_vals[2] += (((tmp2 + tmp5) + (1 << ((3) - 1))) >> 3);
        out_vals[3] += (((tmp3 - tmp4) + (1 << ((3) - 1))) >> 3);
        out_vals[4] += (((tmp3 + tmp4) + (1 << ((3) - 1))) >> 3);
        out_vals[5] += (((tmp2 - tmp5) + (1 << ((3) - 1))) >> 3);
        out_vals[6] += (((tmp1 - tmp6) + (1 << ((3) - 1))) >> 3);
        out_vals[7] += (((tmp0 - tmp7) + (1 << ((3) - 1))) >> 3);

        for (int i = 0; i < 8; i++) {
            outptr[i * output_stride] = out_vals[i];
        }

        outptr++;
        wsptr += 8;
    }
}
