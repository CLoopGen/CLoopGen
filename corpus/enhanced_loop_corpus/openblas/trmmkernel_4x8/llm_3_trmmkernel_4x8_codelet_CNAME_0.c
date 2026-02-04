#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bn;
extern BLASLONG bk;
extern float alpha;
extern float *ba;
extern float *bb;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG offset;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float *C0;
extern float *C1;
extern float *C2;
extern float *C3;
extern float *C4;
extern float *C5;
extern float *C6;
extern float *C7;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res4_0;
extern float res4_1;
extern float res4_2;
extern float res4_3;
extern float res5_0;
extern float res5_1;
extern float res5_2;
extern float res5_3;
extern float res6_0;
extern float res6_1;
extern float res6_2;
extern float res6_3;
extern float res7_0;
extern float res7_1;
extern float res7_2;
extern float res7_3;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern float b4;
extern float b5;
extern float b6;
extern float b7;
extern BLASLONG off;
extern BLASLONG temp;
extern _Bool left;
extern _Bool backwards;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 8; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C1 + ldc;
    C3 = C2 + ldc;
    C4 = C3 + ldc;
    C5 = C4 + ldc;
    C6 = C5 + ldc;
    C7 = C6 + ldc;
    if (left) {
        off = offset;
    }
    ptrba = ba;
    for (i = 0; i < bm / 4; i += 1) {
        ptrbb = bb;
        if (backwards) {
            ptrba += off * 4;
            ptrbb += off * 8;
        }
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = 0;
        res2_0 = res2_1 = res2_2 = res2_3 = 0;
        res3_0 = res3_1 = res3_2 = res3_3 = 0;
        res4_0 = res4_1 = res4_2 = res4_3 = 0;
        res5_0 = res5_1 = res5_2 = res5_3 = 0;
        res6_0 = res6_1 = res6_2 = res6_3 = 0;
        res7_0 = res7_1 = res7_2 = res7_3 = 0;
        temp = backwards ? bk - off : left ? off + 4 : off + 8;
        for (k = 0; k < temp; k++) {
            float b_vals[8] = {ptrbb[0], ptrbb[1], ptrbb[2], ptrbb[3],
                               ptrbb[4], ptrbb[5], ptrbb[6], ptrbb[7]};
            float a_vals[4] = {ptrba[0], ptrba[1], ptrba[2], ptrba[3]};
            for (int m = 0; m < 4; m++) {
                float a = a_vals[m];
                res0_0 += a * b_vals[0]; res1_0 += a * b_vals[1];
                res2_0 += a * b_vals[2]; res3_0 += a * b_vals[3];
                res4_0 += a * b_vals[4]; res5_0 += a * b_vals[5];
                res6_0 += a * b_vals[6]; res7_0 += a * b_vals[7];
                if (m == 0) res0_1 = res1_1 = res2_1 = res3_1 = res4_1 = res5_1 = res6_1 = res7_1 = 0;
                if (m == 1) res0_2 = res1_2 = res2_2 = res3_2 = res4_2 = res5_2 = res6_2 = res7_2 = 0;
                if (m == 2) res0_3 = res1_3 = res2_3 = res3_3 = res4_3 = res5_3 = res6_3 = res7_3 = 0;
            }
            ptrba += 4;
            ptrbb += 8;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha; res2_2 *= alpha; res2_3 *= alpha;
        res3_0 *= alpha; res3_1 *= alpha; res3_2 *= alpha; res3_3 *= alpha;
        res4_0 *= alpha; res4_1 *= alpha; res4_2 *= alpha; res4_3 *= alpha;
        res5_0 *= alpha; res5_1 *= alpha; res5_2 *= alpha; res5_3 *= alpha;
        res6_0 *= alpha; res6_1 *= alpha; res6_2 *= alpha; res6_3 *= alpha;
        res7_0 *= alpha; res7_1 *= alpha; res7_2 *= alpha; res7_3 *= alpha;
        float* c_ptrs[8][4] = {
            {C0, C0+1, C0+2, C0+3}, {C1, C1+1, C1+2, C1+3},
            {C2, C2+1, C2+2, C2+3}, {C3, C3+1, C3+2, C3+3},
            {C4, C4+1, C4+2, C4+3}, {C5, C5+1, C5+2, C5+3},
            {C6, C6+1, C6+2, C6+3}, {C7, C7+1, C7+2, C7+3}
        };
        float res_vals[8][4] = {
            {res0_0, res0_1, res0_2, res0_3}, {res1_0, res1_1, res1_2, res1_3},
            {res2_0, res2_1, res2_2, res2_3}, {res3_0, res3_1, res3_2, res3_3},
            {res4_0, res4_1, res4_2, res4_3}, {res5_0, res5_1, res5_2, res5_3},
            {res6_0, res6_1, res6_2, res6_3}, {res7_0, res7_1, res7_2, res7_3}
        };
        for (int r = 0; r < 8; r++) {
            for (int s = 0; s < 4; s++) {
                c_ptrs[r][s][0] = res_vals[r][s];
            }
        }
        if (!backwards) {
            temp = (bk - off);
            temp = left ? temp - 4 : temp - 8;
            ptrba += temp * 4;
            ptrbb += temp * 8;
        }
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
        C4 += 4; C5 += 4; C6 += 4; C7 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = res1_0 = res1_1 = 0;
        res2_0 = res2_1 = res3_0 = res3_1 = 0;
        res4_0 = res4_1 = res5_0 = res5_1 = 0;
        res6_0 = res6_1 = res7_0 = res7_1 = 0;
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            float b_vals[8] = {ptrbb[0], ptrbb[1], ptrbb[2], ptrbb[3],
                               ptrbb[4], ptrbb[5], ptrbb[6], ptrbb[7]};
            a0 = ptrba[0]; a1 = ptrba[1];
            res0_0 += a0 * b_vals[0]; res1_0 += a0 * b_vals[1]; res2_0 += a0 * b_vals[2];
            res3_0 += a0 * b_vals[3]; res4_0 += a0 * b_vals[4]; res5_0 += a0 * b_vals[5];
            res6_0 += a0 * b_vals[6]; res7_0 += a0 * b_vals[7];
            res0_1 += a1 * b_vals[0]; res1_1 += a1 * b_vals[1]; res2_1 += a1 * b_vals[2];
            res3_1 += a1 * b_vals[3]; res4_1 += a1 * b_vals[4]; res5_1 += a1 * b_vals[5];
            res6_1 += a1 * b_vals[6]; res7_1 += a1 * b_vals[7];
            ptrba += 2;
            ptrbb += 8;
        }
        res0_0 *= alpha; res0_1 *= alpha; res1_0 *= alpha; res1_1 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha; res3_0 *= alpha; res3_1 *= alpha;
        res4_0 *= alpha; res4_1 *= alpha; res5_0 *= alpha; res5_1 *= alpha;
        res6_0 *= alpha; res6_1 *= alpha; res7_0 *= alpha; res7_1 *= alpha;
        float* c2_ptrs[8][2] = {
            {C0, C0+1}, {C1, C1+1}, {C2, C2+1}, {C3, C3+1},
            {C4, C4+1}, {C5, C5+1}, {C6, C6+1}, {C7, C7+1}
        };
        float res2_vals[8][2] = {
            {res0_0, res0_1}, {res1_0, res1_1}, {res2_0, res2_1}, {res3_0, res3_1},
            {res4_0, res4_1}, {res5_0, res5_1}, {res6_0, res6_1}, {res7_0, res7_1}
        };
        for (int r = 0; r < 8; r++) {
            for (int s = 0; s < 2; s++) {
                c2_ptrs[r][s][0] = res2_vals[r][s];
            }
        }
        temp = bk - off - 8;
        ptrba += temp * 2;
        ptrbb += temp * 8;
        C0 += 2; C1 += 2; C2 += 2; C3 += 2;
        C4 += 2; C5 += 2; C6 += 2; C7 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = res1_0 = res2_0 = res3_0 = 0;
        res4_0 = res5_0 = res6_0 = res7_0 = 0;
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            float b_vals[8] = {ptrbb[0], ptrbb[1], ptrbb[2], ptrbb[3],
                               ptrbb[4], ptrbb[5], ptrbb[6], ptrbb[7]};
            a0 = ptrba[0];
            res0_0 += a0 * b_vals[0]; res1_0 += a0 * b_vals[1]; res2_0 += a0 * b_vals[2];
            res3_0 += a0 * b_vals[3]; res4_0 += a0 * b_vals[4]; res5_0 += a0 * b_vals[5];
            res6_0 += a0 * b_vals[6]; res7_0 += a0 * b_vals[7];
            ptrba += 1;
            ptrbb += 8;
        }
        res0_0 *= alpha; res1_0 *= alpha; res2_0 *= alpha; res3_0 *= alpha;
        res4_0 *= alpha; res5_0 *= alpha; res6_0 *= alpha; res7_0 *= alpha;
        float* c1_ptrs[8] = {C0, C1, C2, C3, C4, C5, C6, C7};
        float res1_vals[8] = {res0_0, res1_0, res2_0, res3_0, res4_0, res5_0, res6_0, res7_0};
        for (int r = 0; r < 8; r++) {
            c1_ptrs[r][0] = res1_vals[r];
        }
        temp = bk - off - 8;
        ptrba += temp;
        ptrbb += temp * 8;
        C0++; C1++; C2++; C3++;
        C4++; C5++; C6++; C7++;
    }
    bb += bk * 8;
    C += ldc * 8;
}
}
