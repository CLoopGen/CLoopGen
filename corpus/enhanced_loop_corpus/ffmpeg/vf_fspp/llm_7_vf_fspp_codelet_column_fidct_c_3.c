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
        // Eliminate loop-carried dependency by unrolling two iterations manually
        for (ctr = 8; ctr > 0; ctr -= 2) {
            // First iteration (original index)
            int16_t *dp0 = dataptr;
            int16_t *wp0 = wsptr;
            int16_t *th0 = threshold;

            tmp0 = dp0[8 * 0] + dp0[8 * 7];
            tmp7 = dp0[8 * 0] - dp0[8 * 7];
            tmp1 = dp0[8 * 1] + dp0[8 * 6];
            tmp6 = dp0[8 * 1] - dp0[8 * 6];
            tmp2 = dp0[8 * 2] + dp0[8 * 5];
            tmp5 = dp0[8 * 2] - dp0[8 * 5];
            tmp3 = dp0[8 * 3] + dp0[8 * 4];
            tmp4 = dp0[8 * 3] - dp0[8 * 4];

            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            d0 = tmp10 + tmp11;
            d4 = tmp10 - tmp11;
            z1 = ((((tmp12 + tmp13) << 2) * FIX_0_707106781) >> 16);
            d2 = tmp13 + z1;
            d6 = tmp13 - z1;

            tmp0 = (((unsigned int)(d0 + th0[0 * 8])) > th0[0 * 8] * 2) ? d0 : 0;
            tmp1 = (((unsigned int)(d2 + th0[2 * 8])) > th0[2 * 8] * 2) ? d2 : 0;
            tmp2 = (((unsigned int)(d4 + th0[4 * 8])) > th0[4 * 8] * 2) ? d4 : 0;
            tmp3 = (((unsigned int)(d6 + th0[6 * 8])) > th0[6 * 8] * 2) ? d6 : 0;

            tmp0 += 2;
            int_simd16_t t10a = (tmp0 + tmp2) >> 2;
            int_simd16_t t11a = (tmp0 - tmp2) >> 2;
            int_simd16_t t13a = (tmp1 + tmp3) >> 2;
            int_simd16_t t12a = ((((tmp1 - tmp3)) * FIX_1_414213562_A) >> 16) - t13a;

            int_simd16_t out0a = t10a + t13a;
            int_simd16_t out3a = t10a - t13a;
            int_simd16_t out1a = t11a + t12a;
            int_simd16_t out2a = t11a - t12a;

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

            tmp4 = (((unsigned int)(d1 + th0[1 * 8])) > th0[1 * 8] * 2) ? d1 : 0;
            tmp5 = (((unsigned int)(d3 + th0[3 * 8])) > th0[3 * 8] * 2) ? d3 : 0;
            tmp6 = (((unsigned int)(d5 + th0[5 * 8])) > th0[5 * 8] * 2) ? d5 : 0;
            tmp7 = (((unsigned int)(d7 + th0[7 * 8])) > th0[7 * 8] * 2) ? d7 : 0;

            z13 = tmp6 + tmp5;
            z10 = (tmp6 - tmp5) << 1;
            z11 = tmp4 + tmp7;
            z12 = (tmp4 - tmp7) << 1;
            tmp7 = (z11 + z13) >> 2;
            tmp11 = ((((z11 - z13) << 1) * FIX_1_414213562) >> 16);
            z5 = (((z10 + z12) * FIX_1_847759065) >> 16);
            tmp10 = (((z12) * FIX_1_082392200) >> 16) - z5;
            tmp12 = (((z10) * FIX_2_613125930) >> 16) + z5;
            int_simd16_t out6a = tmp12 - tmp7;
            int_simd16_t out5a = tmp11 - out6a;
            int_simd16_t out4a = tmp10 + out5a;

            // Second iteration (next element)
            int16_t *dp1 = dp0 + 1;
            int16_t *wp1 = wp0 + 1;
            int16_t *th1 = th0 + 1;

            tmp0 = dp1[8 * 0] + dp1[8 * 7];
            tmp7 = dp1[8 * 0] - dp1[8 * 7];
            tmp1 = dp1[8 * 1] + dp1[8 * 6];
            tmp6 = dp1[8 * 1] - dp1[8 * 6];
            tmp2 = dp1[8 * 2] + dp1[8 * 5];
            tmp5 = dp1[8 * 2] - dp1[8 * 5];
            tmp3 = dp1[8 * 3] + dp1[8 * 4];
            tmp4 = dp1[8 * 3] - dp1[8 * 4];

            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;
            d0 = tmp10 + tmp11;
            d4 = tmp10 - tmp11;
            z1 = ((((tmp12 + tmp13) << 2) * FIX_0_707106781) >> 16);
            d2 = tmp13 + z1;
            d6 = tmp13 - z1;

            tmp0 = (((unsigned int)(d0 + th1[0 * 8])) > th1[0 * 8] * 2) ? d0 : 0;
            tmp1 = (((unsigned int)(d2 + th1[2 * 8])) > th1[2 * 8] * 2) ? d2 : 0;
            tmp2 = (((unsigned int)(d4 + th1[4 * 8])) > th1[4 * 8] * 2) ? d4 : 0;
            tmp3 = (((unsigned int)(d6 + th1[6 * 8])) > th1[6 * 8] * 2) ? d6 : 0;

            tmp0 += 2;
            int_simd16_t t10b = (tmp0 + tmp2) >> 2;
            int_simd16_t t11b = (tmp0 - tmp2) >> 2;
            int_simd16_t t13b = (tmp1 + tmp3) >> 2;
            int_simd16_t t12b = ((((tmp1 - tmp3)) * FIX_1_414213562_A) >> 16) - t13b;

            int_simd16_t out0b = t10b + t13b;
            int_simd16_t out3b = t10b - t13b;
            int_simd16_t out1b = t11b + t12b;
            int_simd16_t out2b = t11b - t12b;

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

            tmp4 = (((unsigned int)(d1 + th1[1 * 8])) > th1[1 * 8] * 2) ? d1 : 0;
            tmp5 = (((unsigned int)(d3 + th1[3 * 8])) > th1[3 * 8] * 2) ? d3 : 0;
            tmp6 = (((unsigned int)(d5 + th1[5 * 8])) > th1[5 * 8] * 2) ? d5 : 0;
            tmp7 = (((unsigned int)(d7 + th1[7 * 8])) > th1[7 * 8] * 2) ? d7 : 0;

            z13 = tmp6 + tmp5;
            z10 = (tmp6 - tmp5) << 1;
            z11 = tmp4 + tmp7;
            z12 = (tmp4 - tmp7) << 1;
            tmp7 = (z11 + z13) >> 2;
            tmp11 = ((((z11 - z13) << 1) * FIX_1_414213562) >> 16);
            z5 = (((z10 + z12) * FIX_1_847759065) >> 16);
            tmp10 = (((z12) * FIX_1_082392200) >> 16) - z5;
            tmp12 = (((z10) * FIX_2_613125930) >> 16) + z5;
            int_simd16_t out6b = tmp12 - tmp7;
            int_simd16_t out5b = tmp11 - out6b;
            int_simd16_t out4b = tmp10 + out5b;

            // Write back both results
            wp0[8 * 0] += (out0a + (out6a - out5a + out4a)); // Simplified mapping
            wp0[8 * 1] += (out1a + out6a);
            wp0[8 * 2] += (out2a + out5a);
            wp0[8 * 3] += (out3a - out4a);
            wp0[8 * 4] += (out3a + out4a);
            wp0[8 * 5] += (out2a - out5a);
            wp0[8 * 6] = (out1a - out6a);
            wp0[8 * 7] = (out0a - (out6a - out5a + out4a));

            wp1[8 * 0] += (out0b + (out6b - out5b + out4b));
            wp1[8 * 1] += (out1b + out6b);
            wp1[8 * 2] += (out2b + out5b);
            wp1[8 * 3] += (out3b - out4b);
            wp1[8 * 4] += (out3b + out4b);
            wp1[8 * 5] += (out2b - out5b);
            wp1[8 * 6] = (out1b - out6b);
            wp1[8 * 7] = (out0b - (out6b - out5b + out4b));

            // Advance pointers by 2 to match unroll
            dataptr += 2;
            wsptr += 2;
            threshold += 2;
        }
        dataptr += 8;
        wsptr += 8;
    }
}
