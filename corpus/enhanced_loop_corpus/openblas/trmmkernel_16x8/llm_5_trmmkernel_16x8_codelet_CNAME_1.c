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

        for (k = 0; k <= off; k++) {
            b0 = *ptrbb++;
            a0 = *ptrba++; res0_0 += a0 * b0;
            a1 = *ptrba++; res0_1 += a1 * b0;
            a0 = *ptrba++; res0_2 += a0 * b0;
            a1 = *ptrba++; res0_3 += a1 * b0;
            a0 = *ptrba++; res0_4 += a0 * b0;
            a1 = *ptrba++; res0_5 += a1 * b0;
            a0 = *ptrba++; res0_6 += a0 * b0;
            a1 = *ptrba++; res0_7 += a1 * b0;
            a0 = *ptrba++; res0_8 += a0 * b0;
            a1 = *ptrba++; res0_9 += a1 * b0;
            a0 = *ptrba++; res0_10 += a0 * b0;
            a1 = *ptrba++; res0_11 += a1 * b0;
            a0 = *ptrba++; res0_12 += a0 * b0;
            a1 = *ptrba++; res0_13 += a1 * b0;
            a0 = *ptrba++; res0_14 += a0 * b0;
            a1 = *ptrba++; res0_15 += a1 * b0;
        }

        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        res0_8 *= alpha; res0_9 *= alpha; res0_10 *= alpha; res0_11 *= alpha;
        res0_12 *= alpha; res0_13 *= alpha; res0_14 *= alpha; res0_15 *= alpha;

        *C0++ = res0_0; *C0++ = res0_1; *C0++ = res0_2; *C0++ = res0_3;
        *C0++ = res0_4; *C0++ = res0_5; *C0++ = res0_6; *C0++ = res0_7;
        *C0++ = res0_8; *C0++ = res0_9; *C0++ = res0_10; *C0++ = res0_11;
        *C0++ = res0_12; *C0++ = res0_13; *C0++ = res0_14; *C0++ = res0_15;

        temp = bk - off - 1;
        ptrba += temp * 16;
        ptrbb += temp;
    }

    temp = bm & 15;
    if (temp > 0) {
        ptrbb = bb;
        if (temp >= 8) {
            res0_0 = res0_1 = res0_2 = res0_3 = 0;
            res0_4 = res0_5 = res0_6 = res0_7 = 0;
            for (k = 0; k <= off; k++) {
                b0 = *ptrbb++;
                a0 = *ptrba++; res0_0 += a0 * b0;
                a1 = *ptrba++; res0_1 += a1 * b0;
                a0 = *ptrba++; res0_2 += a0 * b0;
                a1 = *ptrba++; res0_3 += a1 * b0;
                a0 = *ptrba++; res0_4 += a0 * b0;
                a1 = *ptrba++; res0_5 += a1 * b0;
                a0 = *ptrba++; res0_6 += a0 * b0;
                a1 = *ptrba++; res0_7 += a1 * b0;
            }
            res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
            res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
            *C0++ = res0_0; *C0++ = res0_1; *C0++ = res0_2; *C0++ = res0_3;
            *C0++ = res0_4; *C0++ = res0_5; *C0++ = res0_6; *C0++ = res0_7;
            temp -= 8;
        }

        if (temp >= 4) {
            res0_0 = res0_1 = res0_2 = res0_3 = 0;
            for (k = 0; k <= off; k++) {
                b0 = *ptrbb++;
                a0 = *ptrba++; res0_0 += a0 * b0;
                a1 = *ptrba++; res0_1 += a1 * b0;
                a0 = *ptrba++; res0_2 += a0 * b0;
                a1 = *ptrba++; res0_3 += a1 * b0;
            }
            res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
            *C0++ = res0_0; *C0++ = res0_1; *C0++ = res0_2; *C0++ = res0_3;
            temp -= 4;
        }

        if (temp >= 2) {
            res0_0 = res0_1 = 0;
            for (k = 0; k <= off; k++) {
                b0 = *ptrbb++;
                a0 = *ptrba++; res0_0 += a0 * b0;
                a1 = *ptrba++; res0_1 += a1 * b0;
            }
            res0_0 *= alpha; res0_1 *= alpha;
            *C0++ = res0_0; *C0++ = res0_1;
            temp -= 2;
        }

        if (temp == 1) {
            res0_0 = 0;
            for (k = 0; k <= off; k++) {
                b0 = *ptrbb++;
                a0 = *ptrba++; res0_0 += a0 * b0;
            }
            res0_0 *= alpha;
            *C0++ = res0_0;
        }

        temp = bk - off - 1;
        ptrba += temp * (bm & 15);
        ptrbb += temp;
    }

    bb += bk;
    C += ldc;
}
}
