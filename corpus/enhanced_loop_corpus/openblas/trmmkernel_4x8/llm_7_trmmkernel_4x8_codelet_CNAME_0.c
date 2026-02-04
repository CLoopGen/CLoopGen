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
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];
            a0 = ptrba[0]; a1 = ptrba[1]; 
            float pa0 = a0 * b0, pa1 = a0 * b1, pa2 = a0 * b2, pa3 = a0 * b3;
            float pa4 = a0 * b4, pa5 = a0 * b5, pa6 = a0 * b6, pa7 = a0 * b7;
            res0_0 += pa0; res1_0 += pa1; res2_0 += pa2; res3_0 += pa3;
            res4_0 += pa4; res5_0 += pa5; res6_0 += pa6; res7_0 += pa7;

            pa0 = a1 * b0; pa1 = a1 * b1; pa2 = a1 * b2; pa3 = a1 * b3;
            pa4 = a1 * b4; pa5 = a1 * b5; pa6 = a1 * b6; pa7 = a1 * b7;
            res0_1 += pa0; res1_1 += pa1; res2_1 += pa2; res3_1 += pa3;
            res4_1 += pa4; res5_1 += pa5; res6_1 += pa6; res7_1 += pa7;

            a0 = ptrba[2]; a1 = ptrba[3];
            pa0 = a0 * b0; pa1 = a0 * b1; pa2 = a0 * b2; pa3 = a0 * b3;
            pa4 = a0 * b4; pa5 = a0 * b5; pa6 = a0 * b6; pa7 = a0 * b7;
            res0_2 += pa0; res1_2 += pa1; res2_2 += pa2; res3_2 += pa3;
            res4_2 += pa4; res5_2 += pa5; res6_2 += pa6; res7_2 += pa7;

            pa0 = a1 * b0; pa1 = a1 * b1; pa2 = a1 * b2; pa3 = a1 * b3;
            pa4 = a1 * b4; pa5 = a1 * b5; pa6 = a1 * b6; pa7 = a1 * b7;
            res0_3 += pa0; res1_3 += pa1; res2_3 += pa2; res3_3 += pa3;
            res4_3 += pa4; res5_3 += pa5; res6_3 += pa6; res7_3 += pa7;

            ptrba += 4;
            ptrbb += 8;
        }
        float scaled_alpha = alpha;
        res0_0 *= scaled_alpha; res0_1 *= scaled_alpha; res0_2 *= scaled_alpha; res0_3 *= scaled_alpha;
        res1_0 *= scaled_alpha; res1_1 *= scaled_alpha; res1_2 *= scaled_alpha; res1_3 *= scaled_alpha;
        res2_0 *= scaled_alpha; res2_1 *= scaled_alpha; res2_2 *= scaled_alpha; res2_3 *= scaled_alpha;
        res3_0 *= scaled_alpha; res3_1 *= scaled_alpha; res3_2 *= scaled_alpha; res3_3 *= scaled_alpha;
        res4_0 *= scaled_alpha; res4_1 *= scaled_alpha; res4_2 *= scaled_alpha; res4_3 *= scaled_alpha;
        res5_0 *= scaled_alpha; res5_1 *= scaled_alpha; res5_2 *= scaled_alpha; res5_3 *= scaled_alpha;
        res6_0 *= scaled_alpha; res6_1 *= scaled_alpha; res6_2 *= scaled_alpha; res6_3 *= scaled_alpha;
        res7_0 *= scaled_alpha; res7_1 *= scaled_alpha; res7_2 *= scaled_alpha; res7_3 *= scaled_alpha;

        *C0++ = res0_0; *C0++ = res0_1; *C0++ = res0_2; *C0++ = res0_3;
        *C1++ = res1_0; *C1++ = res1_1; *C1++ = res1_2; *C1++ = res1_3;
        *C2++ = res2_0; *C2++ = res2_1; *C2++ = res2_2; *C2++ = res2_3;
        *C3++ = res3_0; *C3++ = res3_1; *C3++ = res3_2; *C3++ = res3_3;
        *C4++ = res4_0; *C4++ = res4_1; *C4++ = res4_2; *C4++ = res4_3;
        *C5++ = res5_0; *C5++ = res5_1; *C5++ = res5_2; *C5++ = res5_3;
        *C6++ = res6_0; *C6++ = res6_1; *C6++ = res6_2; *C6++ = res6_3;
        *C7++ = res7_0; *C7++ = res7_1; *C7++ = res7_2; *C7++ = res7_3;

        if (!backwards) {
            temp = bk - off;
            temp = left ? temp - 4 : temp - 8;
            ptrba += temp * 4;
            ptrbb += temp * 8;
        }
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = res1_0 = res1_1 = 0;
        res2_0 = res2_1 = res3_0 = res3_1 = 0;
        res4_0 = res4_1 = res5_0 = res5_1 = 0;
        res6_0 = res6_1 = res7_0 = res7_1 = 0;
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];
            a0 = ptrba[0]; a1 = ptrba[1];
            float p0 = a0 * b0, p1 = a0 * b1, p2 = a0 * b2, p3 = a0 * b3;
            float p4 = a0 * b4, p5 = a0 * b5, p6 = a0 * b6, p7 = a0 * b7;
            res0_0 += p0; res1_0 += p1; res2_0 += p2; res3_0 += p3;
            res4_0 += p4; res5_0 += p5; res6_0 += p6; res7_0 += p7;
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
            res4_1 += a1 * b4; res5_1 += a1 * b5; res6_1 += a1 * b6; res7_1 += a1 * b7;
            ptrba += 2;
            ptrbb += 8;
        }
        res0_0 *= alpha; res0_1 *= alpha; res1_0 *= alpha; res1_1 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha; res3_0 *= alpha; res3_1 *= alpha;
        res4_0 *= alpha; res4_1 *= alpha; res5_0 *= alpha; res5_1 *= alpha;
        res6_0 *= alpha; res6_1 *= alpha; res7_0 *= alpha; res7_1 *= alpha;

        C0[0] = res0_0; C0[1] = res0_1;
        C1[0] = res1_0; C1[1] = res1_1;
        C2[0] = res2_0; C2[1] = res2_1;
        C3[0] = res3_0; C3[1] = res3_1;
        C4[0] = res4_0; C4[1] = res4_1;
        C5[0] = res5_0; C5[1] = res5_1;
        C6[0] = res6_0; C6[1] = res6_1;
        C7[0] = res7_0; C7[1] = res7_1;

        temp = bk - off - 8;
        ptrba += temp * 2;
        ptrbb += temp * 8;
        C0 += 2; C1 += 2; C2 += 2; C3 += 2;
        C4 += 2; C5 += 2; C6 += 2; C7 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = res1_0 = res2_0 = res3_0 = res4_0 = res5_0 = res6_0 = res7_0 = 0;
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];
            a0 = ptrba[0];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            res4_0 += a0 * b4; res5_0 += a0 * b5; res6_0 += a0 * b6; res7_0 += a0 * b7;
            ptrba++;
            ptrbb += 8;
        }
        res0_0 *= alpha; res1_0 *= alpha; res2_0 *= alpha; res3_0 *= alpha;
        res4_0 *= alpha; res5_0 *= alpha; res6_0 *= alpha; res7_0 *= alpha;
        C0[0] = res0_0; C1[0] = res1_0; C2[0] = res2_0; C3[0] = res3_0;
        C4[0] = res4_0; C5[0] = res5_0; C6[0] = res6_0; C7[0] = res7_0;

        temp = bk - off - 8;
        ptrba += temp;
        ptrbb += temp * 8;
        C0++; C1++; C2++; C3++; C4++; C5++; C6++; C7++;
    }
    bb += bk << 3;
    C += ldc << 3;
}
}
