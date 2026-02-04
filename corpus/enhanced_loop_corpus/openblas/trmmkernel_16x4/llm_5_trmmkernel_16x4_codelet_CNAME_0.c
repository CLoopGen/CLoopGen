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
extern float *C2;
extern float *C3;
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
extern float res0_8;
extern float res0_9;
extern float res0_10;
extern float res0_11;
extern float res0_12;
extern float res0_13;
extern float res0_14;
extern float res0_15;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res1_8;
extern float res1_9;
extern float res1_10;
extern float res1_11;
extern float res1_12;
extern float res1_13;
extern float res1_14;
extern float res1_15;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res2_8;
extern float res2_9;
extern float res2_10;
extern float res2_11;
extern float res2_12;
extern float res2_13;
extern float res2_14;
extern float res2_15;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
extern float res3_8;
extern float res3_9;
extern float res3_10;
extern float res3_11;
extern float res3_12;
extern float res3_13;
extern float res3_14;
extern float res3_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 4; j++) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C0 + 2 * ldc;
    C3 = C0 + 3 * ldc;
    ptrba = ba;

    BLASLONG block_mask = 16;
    for (i = 0; i < bm; ) {
        BLASLONG step = 0;
        if ((bm - i) >= 16) {
            step = 16;
        } else if ((bm - i) >= 8) {
            step = 8;
        } else if ((bm - i) >= 4) {
            step = 4;
        } else if ((bm - i) >= 2) {
            step = 2;
        } else {
            step = 1;
        }

        ptrbb = bb;
        temp = off + 4;

        switch (step) {
            case 16:
                res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 =
                res0_8 = res0_9 = res0_10 = res0_11 = res0_12 = res0_13 = res0_14 = res0_15 = 0;
                res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 =
                res1_8 = res1_9 = res1_10 = res1_11 = res1_12 = res1_13 = res1_14 = res1_15 = 0;
                res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 =
                res2_8 = res2_9 = res2_10 = res2_11 = res2_12 = res2_13 = res2_14 = res2_15 = 0;
                res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 =
                res3_8 = res3_9 = res3_10 = res3_11 = res3_12 = res3_13 = res3_14 = res3_15 = 0;

                for (k = 0; k < temp; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
                    #define MACC(idx, r0, r1, r2, r3) \
                        a0 = ptrba[idx]; \
                        r0 += a0 * b0; r1 += a0 * b1; r2 += a0 * b2; r3 += a0 * b3;

                    MACC(0, res0_0, res1_0, res2_0, res3_0)
                    MACC(1, res0_1, res1_1, res2_1, res3_1)
                    MACC(2, res0_2, res1_2, res2_2, res3_2)
                    MACC(3, res0_3, res1_3, res2_3, res3_3)
                    MACC(4, res0_4, res1_4, res2_4, res3_4)
                    MACC(5, res0_5, res1_5, res2_5, res3_5)
                    MACC(6, res0_6, res1_6, res2_6, res3_6)
                    MACC(7, res0_7, res1_7, res2_7, res3_7)
                    MACC(8, res0_8, res1_8, res2_8, res3_8)
                    MACC(9, res0_9, res1_9, res2_9, res3_9)
                    MACC(10, res0_10, res1_10, res2_10, res3_10)
                    MACC(11, res0_11, res1_11, res2_11, res3_11)
                    MACC(12, res0_12, res1_12, res2_12, res3_12)
                    MACC(13, res0_13, res1_13, res2_13, res3_13)
                    MACC(14, res0_14, res1_14, res2_14, res3_14)
                    MACC(15, res0_15, res1_15, res2_15, res3_15)

                    #undef MACC
                    ptrba += 16;
                    ptrbb += 4;
                }

                for (int idx = 0; idx < 16; ++idx) {
                    *((float*)(&res0_0) + idx) *= alpha;
                    *((float*)(&res1_0) + idx) *= alpha;
                    *((float*)(&res2_0) + idx) *= alpha;
                    *((float*)(&res3_0) + idx) *= alpha;
                }

                for (int idx = 0; idx < 16; ++idx) {
                    C0[idx] = *((float*)(&res0_0) + idx);
                    C1[idx] = *((float*)(&res1_0) + idx);
                    C2[idx] = *((float*)(&res2_0) + idx);
                    C3[idx] = *((float*)(&res3_0) + idx);
                }
                break;

            case 8:
                res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0;
                res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 = 0;
                res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 = 0;
                res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 = 0;

                for (k = 0; k < temp; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
                    a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
                    a0 = ptrba[2]; res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
                    a1 = ptrba[3]; res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;
                    a0 = ptrba[4]; res0_4 += a0 * b0; res1_4 += a0 * b1; res2_4 += a0 * b2; res3_4 += a0 * b3;
                    a1 = ptrba[5]; res0_5 += a1 * b0; res1_5 += a1 * b1; res2_5 += a1 * b2; res3_5 += a1 * b3;
                    a0 = ptrba[6]; res0_6 += a0 * b0; res1_6 += a0 * b1; res2_6 += a0 * b2; res3_6 += a0 * b3;
                    a1 = ptrba[7]; res0_7 += a1 * b0; res1_7 += a1 * b1; res2_7 += a1 * b2; res3_7 += a1 * b3;

                    ptrba += 8;
                    ptrbb += 4;
                }

                for (int idx = 0; idx < 8; ++idx) {
                    *((float*)(&res0_0) + idx) *= alpha;
                    *((float*)(&res1_0) + idx) *= alpha;
                    *((float*)(&res2_0) + idx) *= alpha;
                    *((float*)(&res3_0) + idx) *= alpha;
                }

                for (int idx = 0; idx < 8; ++idx) {
                    C0[idx] = *((float*)(&res0_0) + idx);
                    C1[idx] = *((float*)(&res1_0) + idx);
                    C2[idx] = *((float*)(&res2_0) + idx);
                    C3[idx] = *((float*)(&res3_0) + idx);
                }
                break;

            case 4:
                res0_0 = res0_1 = res0_2 = res0_3 = 0;
                res1_0 = res1_1 = res1_2 = res1_3 = 0;
                res2_0 = res2_1 = res2_2 = res2_3 = 0;
                res3_0 = res3_1 = res3_2 = res3_3 = 0;

                for (k = 0; k < temp; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
                    a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
                    a0 = ptrba[2]; res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
                    a1 = ptrba[3]; res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;

                    ptrba += 4;
                    ptrbb += 4;
                }

                res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
                res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
                res2_0 *= alpha; res2_1 *= alpha; res2_2 *= alpha; res2_3 *= alpha;
                res3_0 *= alpha; res3_1 *= alpha; res3_2 *= alpha; res3_3 *= alpha;

                C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
                C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
                C2[0] = res2_0; C2[1] = res2_1; C2[2] = res2_2; C2[3] = res2_3;
                C3[0] = res3_0; C3[1] = res3_1; C3[2] = res3_2; C3[3] = res3_3;
                break;

            case 2:
                res0_0 = res0_1 = 0; res1_0 = res1_1 = 0;
                res2_0 = res2_1 = 0; res3_0 = res3_1 = 0;

                for (k = 0; k < temp; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
                    a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;

                    ptrba += 2;
                    ptrbb += 4;
                }

                res0_0 *= alpha; res0_1 *= alpha;
                res1_0 *= alpha; res1_1 *= alpha;
                res2_0 *= alpha; res2_1 *= alpha;
                res3_0 *= alpha; res3_1 *= alpha;

                C0[0] = res0_0; C0[1] = res0_1;
                C1[0] = res1_0; C1[1] = res1_1;
                C2[0] = res2_0; C2[1] = res2_1;
                C3[0] = res3_0; C3[1] = res3_1;
                break;

            case 1:
                res0_0 = res1_0 = res2_0 = res3_0 = 0;

                for (k = 0; k < temp; k++) {
                    b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
                    a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;

                    ptrba++;
                    ptrbb += 4;
                }

                res0_0 *= alpha; res1_0 *= alpha; res2_0 *= alpha; res3_0 *= alpha;
                C0[0] = res0_0; C1[0] = res1_0; C2[0] = res2_0; C3[0] = res3_0;
                break;
        }

        temp = bk - off - 4;
        ptrba += temp * step;
        ptrbb += temp * 4;
        C0 += step; C1 += step; C2 += step; C3 += step;
        i += step;
    }

    bb += (bk << 2);
    C += (ldc << 2);
}
}
