#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t int_simd16_t;

extern  int16_t FIX_0_382683433;
extern  int16_t FIX_0_541196100;
extern  int16_t FIX_0_707106781;
extern  int16_t FIX_1_306562965;
extern  int16_t FIX_1_414213562_A;
extern  int16_t FIX_1_847759065;
extern  int16_t FIX_2_613125930;
extern  int16_t FIX_1_414213562;
extern  int16_t FIX_1_082392200;
extern int16_t *thr_adr;
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
extern int_simd16_t z10;
extern int_simd16_t z11;
extern int_simd16_t z12;
extern int_simd16_t z13;
extern int_simd16_t d0;
extern int_simd16_t d1;
extern int_simd16_t d2;
extern int_simd16_t d3;
extern int_simd16_t d4;
extern int_simd16_t d5;
extern int_simd16_t d6;
extern int_simd16_t d7;
extern int16_t *dataptr;
extern int16_t *wsptr;
extern int16_t *threshold;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (; cnt > 0; cnt -= 2) {
        threshold = (int16_t *)thr_adr;
        for (ctr = 8; ctr > 0; ctr--) {
            // Change memory access to consecutive indexing via pointer arithmetic
            int16_t *dptr = dataptr;
            int16_t *wptr = wsptr;
            int16_t *tpr = threshold;

            tmp0 = dptr[0] + dptr[7];
            tmp7 = dptr[0] - dptr[7];
            tmp1 = dptr[1] + dptr[6];
            tmp6 = dptr[1] - dptr[6];
            tmp2 = dptr[2] + dptr[5];
            tmp5 = dptr[2] - dptr[5];
            tmp3 = dptr[3] + dptr[4];
            tmp4 = dptr[3] - dptr[4];

            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            d0 = tmp10 + tmp11;
            d4 = tmp10 - tmp11;
            z1 = ((((tmp12 + tmp13) << 2) * FIX_0_707106781)) >> 16;
            d2 = tmp13 + z1;
            d6 = tmp13 - z1;

            if (((unsigned int)((d0) + tpr[0])) > tpr[0] * 2)
                tmp0 = d0;
            else
                tmp0 = 0;

            if (((unsigned int)((d2) + tpr[2])) > tpr[2] * 2)
                tmp1 = d2;
            else
                tmp1 = 0;

            if (((unsigned int)((d4) + tpr[4])) > tpr[4] * 2)
                tmp2 = d4;
            else
                tmp2 = 0;

            if (((unsigned int)((d6) + tpr[6])) > tpr[6] * 2)
                tmp3 = d6;
            else
                tmp3 = 0;

            tmp0 += 2;
            tmp10 = (tmp0 + tmp2) >> 2;
            tmp11 = (tmp0 - tmp2) >> 2;
            tmp13 = (tmp1 + tmp3) >> 2;
            tmp12 = ((((tmp1 - tmp3)) * (FIX_1_414213562_A)) >> 16) - tmp13;
            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            tmp10 = dptr[3] - dptr[4]; // reuse tmp4 logic
            tmp11 = dptr[2] - dptr[5]; // tmp5 + tmp6 equivalent
            tmp12 = dptr[1] - dptr[6]; // tmp6 + tmp7 equivalent
            z5 = ((((tmp10 - tmp12) << 2) * FIX_0_382683433)) >> 16;
            z2 = (((tmp10 << 2) * FIX_0_541196100) >> 16) + z5;
            z4 = (((tmp12 << 2) * FIX_1_306562965) >> 16) + z5;
            z3 = (((tmp11 << 2) * FIX_0_707106781) >> 16);
            z11 = dptr[0] - dptr[7] + z3; // tmp7 + z3
            z13 = dptr[0] - dptr[7] - z3; // tmp7 - z3
            d5 = z13 + z2;
            d3 = z13 - z2;
            d1 = z11 + z4;
            d7 = z11 - z4;

            if (((unsigned int)((d1) + tpr[1])) > tpr[1] * 2)
                tmp4 = d1;
            else
                tmp4 = 0;

            if (((unsigned int)((d3) + tpr[3])) > tpr[3] * 2)
                tmp5 = d3;
            else
                tmp5 = 0;

            if (((unsigned int)((d5) + tpr[5])) > tpr[5] * 2)
                tmp6 = d5;
            else
                tmp6 = 0;

            if (((unsigned int)((d7) + tpr[7])) > tpr[7] * 2)
                tmp7 = d7;
            else
                tmp7 = 0;

            z13 = tmp6 + tmp5;
            z10 = (tmp6 - tmp5) << 1;
            z11 = tmp4 + tmp7;
            z12 = (tmp4 - tmp7) << 1;
            tmp7 = (z11 + z13) >> 2;
            tmp11 = ((((z11 - z13) << 1) * FIX_1_414213562) >> 16);
            z5 = (((z10 + z12) * FIX_1_847759065) >> 16);
            tmp10 = (((z12) * FIX_1_082392200) >> 16) - z5;
            tmp12 = (((z10) * FIX_2_613125930) >> 16) + z5;
            tmp6 = tmp12 - tmp7;
            tmp5 = tmp11 - tmp6;
            tmp4 = tmp10 + tmp5;

            wptr[0] += (tmp0 + tmp7);
            wptr[1] += (tmp1 + tmp6);
            wptr[2] += (tmp2 + tmp5);
            wptr[3] += (tmp3 - tmp4);
            wptr[4] += (tmp3 + tmp4);
            wptr[5] += (tmp2 - tmp5);
            wptr[6] = (tmp1 - tmp6);
            wptr[7] = (tmp0 - tmp7);

            dataptr++;
            wsptr++;
            threshold++;
        }
        dataptr += 8;
        wsptr += 8;
    }
}
