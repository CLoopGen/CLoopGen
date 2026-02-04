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
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG k;
extern float *C0;
extern float *C1;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res0_4;
extern float res0_5;
extern float res0_6;
extern float res0_7;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (bn & 2); j += 2) {
        C0 = C;
        C1 = C0 + ldc;
        ptrba = ba;

        for (i = 0; i < bm; ) {
            ptrbb = bb;
            if (i + 8 <= bm) {
                res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0;
                res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 = 0;
                temp = off + 2;
                for (k = 0; k < temp; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1;
                    a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1;
                    a0 = ptrba[2]; res0_2 += a0 * b0; res1_2 += a0 * b1;
                    a1 = ptrba[3]; res0_3 += a1 * b0; res1_3 += a1 * b1;
                    a0 = ptrba[4]; res0_4 += a0 * b0; res1_4 += a0 * b1;
                    a1 = ptrba[5]; res0_5 += a1 * b0; res1_5 += a1 * b1;
                    a0 = ptrba[6]; res0_6 += a0 * b0; res1_6 += a0 * b1;
                    a1 = ptrba[7]; res0_7 += a1 * b0; res1_7 += a1 * b1;
                    ptrba += 8;
                    ptrbb += 2;
                }
                res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
                res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
                res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
                res1_4 *= alpha; res1_5 *= alpha; res1_6 *= alpha; res1_7 *= alpha;
                C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
                C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
                C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
                C1[4] = res1_4; C1[5] = res1_5; C1[6] = res1_6; C1[7] = res1_7;
                temp = bk - off - 2;
                ptrba += temp * 8;
                ptrbb += temp * 2;
                C0 += 8;
                C1 += 8;
                i += 8;
            }
            else if (i + 4 <= bm) {
                res0_0 = res0_1 = res0_2 = res0_3 = 0;
                res1_0 = res1_1 = res1_2 = res1_3 = 0;
                for (k = 0; k < off + 2; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1;
                    a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1;
                    a0 = ptrba[2]; res0_2 += a0 * b0; res1_2 += a0 * b1;
                    a1 = ptrba[3]; res0_3 += a1 * b0; res1_3 += a1 * b1;
                    ptrba += 4;
                    ptrbb += 2;
                }
                res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
                res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
                C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
                C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
                temp = bk - off - 2;
                ptrba += temp * 4;
                ptrbb += temp * 2;
                C0 += 4;
                C1 += 4;
                i += 4;
            }
            else if (i + 2 <= bm) {
                res0_0 = res0_1 = 0;
                res1_0 = res1_1 = 0;
                for (k = 0; k < off + 2; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1;
                    a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1;
                    ptrba += 2;
                    ptrbb += 2;
                }
                res0_0 *= alpha; res0_1 *= alpha;
                res1_0 *= alpha; res1_1 *= alpha;
                C0[0] = res0_0; C0[1] = res0_1;
                C1[0] = res1_0; C1[1] = res1_1;
                temp = bk - off - 2;
                ptrba += temp * 2;
                ptrbb += temp * 2;
                C0 += 2;
                C1 += 2;
                i += 2;
            }
            else {
                res0_0 = res1_0 = 0;
                for (k = 0; k < off + 2; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1];
                    a0 = ptrba[0];
                    res0_0 += a0 * b0; res1_0 += a0 * b1;
                    ptrba++;
                    ptrbb += 2;
                }
                res0_0 *= alpha; res1_0 *= alpha;
                C0[0] = res0_0; C1[0] = res1_0;
                ptrba += bk - off - 2;
                ptrbb += (bk - off - 2) * 2;
                C0++;
                C1++;
                i++;
            }
        }

        bb += (bk << 1);
        C += (ldc << 1);
    }
}
