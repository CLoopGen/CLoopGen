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
    for (; cnt > 0; cnt -= 4) {
        threshold = (int16_t *)thr_adr;
        for (ctr = 16; ctr > 0; ctr--) {
            tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
            tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
            tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
            tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
            tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
            tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
            tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
            tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            d0 = tmp10 + tmp11;
            d4 = tmp10 - tmp11;

            z1 = ((((tmp12 + tmp13) << 2) * FIX_0_707106781)) >> 16;
            d2 = tmp13 + z1;
            d6 = tmp13 - z1;

            tmp0 = (((unsigned int)(d0 + threshold[0 * 8]) > (unsigned int)(threshold[0 * 8] * 2)) ? d0 : 0);
            tmp1 = (((unsigned int)(d2 + threshold[2 * 8]) > (unsigned int)(threshold[2 * 8] * 2)) ? d2 : 0);
            tmp2 = (((unsigned int)(d4 + threshold[4 * 8]) > (unsigned int)(threshold[4 * 8] * 2)) ? d4 : 0);
            tmp3 = (((unsigned int)(d6 + threshold[6 * 8]) > (unsigned int)(threshold[6 * 8] * 2)) ? d6 : 0);

            tmp0 += 2;
            tmp10 = (tmp0 + tmp2) >> 2;
            tmp11 = (tmp0 - tmp2) >> 2;
            tmp13 = (tmp1 + tmp3) >> 2;
            tmp12 = ((((tmp1 - tmp3)) * FIX_1_414213562_A) >> 16) - tmp13;

            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            tmp10 = tmp4 + tmp5;
            tmp11 = tmp5 + tmp6;
            tmp12 = tmp6 + tmp7;

            z5 = ((((tmp10 - tmp12) << 2) * FIX_0_382683433) >> 16);
            z2 = (((tmp10 << 2) * FIX_0_541196100) >> 16) + z5;
            z4 = (((tmp12 << 2) * FIX_1_306562965) >> 16) + z5;
            z3 = (((tmp11 << 2) * FIX_0_707106781) >> 16);

            z11 = tmp7 + z3;
            z13 = tmp7 - z3;
            d5 = z13 + z2;
            d3 = z13 - z2;
            d1 = z11 + z4;
            d7 = z11 - z4;

            tmp4 = (((unsigned int)(d1 + threshold[1 * 8]) > (unsigned int)(threshold[1 * 8] * 2)) ? d1 : 0);
            tmp5 = (((unsigned int)(d3 + threshold[3 * 8]) > (unsigned int)(threshold[3 * 8] * 2)) ? d3 : 0);
            tmp6 = (((unsigned int)(d5 + threshold[5 * 8]) > (unsigned int)(threshold[5 * 8] * 2)) ? d5 : 0);
            tmp7 = (((unsigned int)(d7 + threshold[7 * 8]) > (unsigned int)(threshold[7 * 8] * 2)) ? d7 : 0);

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

            wsptr[8 * 0] += (tmp0 + tmp7);
            wsptr[8 * 1] += (tmp1 + tmp6);
            wsptr[8 * 2] += (tmp2 + tmp5);
            wsptr[8 * 3] += (tmp3 - tmp4);
            wsptr[8 * 4] += (tmp3 + tmp4);
            wsptr[8 * 5] += (tmp2 - tmp5);
            wsptr[8 * 6] = (tmp1 - tmp6);
            wsptr[8 * 7] = (tmp0 - tmp7);

            dataptr++;
            wsptr++;
            threshold++;

            if (ctr <= 8) continue;

            tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
            tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
            tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
            tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
            tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
            tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
            tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
            tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            d0 = tmp10 + tmp11;
            d4 = tmp10 - tmp11;

            z1 = ((((tmp12 + tmp13) << 2) * FIX_0_707106781)) >> 16;
            d2 = tmp13 + z1;
            d6 = tmp13 - z1;

            tmp0 = (((unsigned int)(d0 + threshold[0 * 8]) > (unsigned int)(threshold[0 * 8] * 2)) ? d0 : 0);
            tmp1 = (((unsigned int)(d2 + threshold[2 * 8]) > (unsigned int)(threshold[2 * 8] * 2)) ? d2 : 0);
            tmp2 = (((unsigned int)(d4 + threshold[4 * 8]) > (unsigned int)(threshold[4 * 8] * 2)) ? d4 : 0);
            tmp3 = (((unsigned int)(d6 + threshold[6 * 8]) > (unsigned int)(threshold[6 * 8] * 2)) ? d6 : 0);

            tmp0 += 2;
            tmp10 = (tmp0 + tmp2) >> 2;
            tmp11 = (tmp0 - tmp2) >> 2;
            tmp13 = (tmp1 + tmp3) >> 2;
            tmp12 = ((((tmp1 - tmp3)) * FIX_1_414213562_A) >> 16) - tmp13;

            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            tmp10 = tmp4 + tmp5;
            tmp11 = tmp5 + tmp6;
            tmp12 = tmp6 + tmp7;

            z5 = ((((tmp10 - tmp12) << 2) * FIX_0_382683433) >> 16);
            z2 = (((tmp10 << 2) * FIX_0_541196100) >> 16) + z5;
            z4 = (((tmp12 << 2) * FIX_1_306562965) >> 16) + z5;
            z3 = (((tmp11 << 2) * FIX_0_707106781) >> 16);

            z11 = tmp7 + z3;
            z13 = tmp7 - z3;
            d5 = z13 + z2;
            d3 = z13 - z2;
            d1 = z11 + z4;
            d7 = z11 - z4;

            tmp4 = (((unsigned int)(d1 + threshold[1 * 8]) > (unsigned int)(threshold[1 * 8] * 2)) ? d1 : 0);
            tmp5 = (((unsigned int)(d3 + threshold[3 * 8]) > (unsigned int)(threshold[3 * 8] * 2)) ? d3 : 0);
            tmp6 = (((unsigned int)(d5 + threshold[5 * 8]) > (unsigned int)(threshold[5 * 8] * 2)) ? d5 : 0);
            tmp7 = (((unsigned int)(d7 + threshold[7 * 8]) > (unsigned int)(threshold[7 * 8] * 2)) ? d7 : 0);

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

            wsptr[8 * 0] += (tmp0 + tmp7);
            wsptr[8 * 1] += (tmp1 + tmp6);
            wsptr[8 * 2] += (tmp2 + tmp5);
            wsptr[8 * 3] += (tmp3 - tmp4);
            wsptr[8 * 4] += (tmp3 + tmp4);
            wsptr[8 * 5] += (tmp2 - tmp5);
            wsptr[8 * 6] = (tmp1 - tmp6);
            wsptr[8 * 7] = (tmp0 - tmp7);

            dataptr++;
            wsptr++;
            threshold++;
        }
        dataptr += 8;
        wsptr += 8;
    }
}
