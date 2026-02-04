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
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;

    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res0_4 = res0_5 = res0_6 = res0_7 = 0;
        res0_8 = res0_9 = res0_10 = res0_11 = 0;
        res0_12 = res0_13 = res0_14 = res0_15 = 0;

        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = *ptrbb;
            res0_0 += ptrba[0]  * b0; res0_1 += ptrba[1]  * b0;
            res0_2 += ptrba[2]  * b0; res0_3 += ptrba[3]  * b0;
            res0_4 += ptrba[4]  * b0; res0_5 += ptrba[5]  * b0;
            res0_6 += ptrba[6]  * b0; res0_7 += ptrba[7]  * b0;
            res0_8 += ptrba[8]  * b0; res0_9 += ptrba[9]  * b0;
            res0_10 += ptrba[10] * b0; res0_11 += ptrba[11] * b0;
            res0_12 += ptrba[12] * b0; res0_13 += ptrba[13] * b0;
            res0_14 += ptrba[14] * b0; res0_15 += ptrba[15] * b0;
            ptrba += 16;
            ptrbb += 1;
        }

        float scaled_alpha = alpha;
        res0_0 *= scaled_alpha; res0_1 *= scaled_alpha; res0_2 *= scaled_alpha; res0_3 *= scaled_alpha;
        res0_4 *= scaled_alpha; res0_5 *= scaled_alpha; res0_6 *= scaled_alpha; res0_7 *= scaled_alpha;
        res0_8 *= scaled_alpha; res0_9 *= scaled_alpha; res0_10 *= scaled_alpha; res0_11 *= scaled_alpha;
        res0_12 *= scaled_alpha; res0_13 *= scaled_alpha; res0_14 *= scaled_alpha; res0_15 *= scaled_alpha;

        float* restrict cptr = C0;
        cptr[0] = res0_0;  cptr[1] = res0_1;  cptr[2] = res0_2;  cptr[3] = res0_3;
        cptr[4] = res0_4;  cptr[5] = res0_5;  cptr[6] = res0_6;  cptr[7] = res0_7;
        cptr[8] = res0_8;  cptr[9] = res0_9;  cptr[10] = res0_10; cptr[11] = res0_11;
        cptr[12] = res0_12; cptr[13] = res0_13; cptr[14] = res0_14; cptr[15] = res0_15;

        temp = (bk - off - 1);
        ptrba += temp * 16;
        ptrbb += temp;
        C0 += 16;
    }

    temp = bm & 15;
    if (temp >= 8) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res0_4 = res0_5 = res0_6 = res0_7 = 0;
        for (k = 0, temp = off + 1; k < temp; k++) {
            b0 = *ptrbb++;
            res0_0 += *ptrba++ * b0; res0_1 += *ptrba++ * b0;
            res0_2 += *ptrba++ * b0; res0_3 += *ptrba++ * b0;
            res0_4 += *ptrba++ * b0; res0_5 += *ptrba++ * b0;
            res0_6 += *ptrba++ * b0; res0_7 += *ptrba++ * b0;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
        temp = bk - off - 1;
        ptrba += temp * 8;
        ptrbb += temp;
        C0 += 8;
        temp = bm & 7;
    }

    if (temp >= 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        for (k = 0, temp = off + 1; k < temp; k++) {
            b0 = *ptrbb++;
            res0_0 += *ptrba++ * b0; res0_1 += *ptrba++ * b0;
            res0_2 += *ptrba++ * b0; res0_3 += *ptrba++ * b0;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        temp = bk - off - 1;
        ptrba += temp * 4;
        ptrbb += temp;
        C0 += 4;
        temp = bm & 3;
    }

    if (temp >= 2) {
        ptrbb = bb;
        res0_0 = res0_1 = 0;
        for (k = 0, temp = off + 1; k < temp; k++) {
            b0 = *ptrbb++;
            res0_0 += *ptrba++ * b0; res0_1 += *ptrba++ * b0;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1;
        temp = bk - off - 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 += 2;
        temp = bm & 1;
    }

    if (temp) {
        ptrbb = bb;
        res0_0 = 0;
        for (k = 0, temp = off + 1; k < temp; k++) {
            res0_0 += (*ptrba++) * (*ptrbb++);
        }
        C0[0] = res0_0 * alpha;
        temp = bk - off - 1;
        ptrba += temp;
        ptrbb += temp;
        C0 += 1;
    }

    bb += bk;
    C += ldc;
}
}
