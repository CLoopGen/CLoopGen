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
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        res0_8 = 0;
        res0_9 = 0;
        res0_10 = 0;
        res0_11 = 0;
        res0_12 = 0;
        res0_13 = 0;
        res0_14 = 0;
        res0_15 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[k];  
            res0_0 += ptrba[ 0] * b_val;
            res0_1 += ptrba[ 1] * b_val;
            res0_2 += ptrba[ 2] * b_val;
            res0_3 += ptrba[ 3] * b_val;
            res0_4 += ptrba[ 4] * b_val;
            res0_5 += ptrba[ 5] * b_val;
            res0_6 += ptrba[ 6] * b_val;
            res0_7 += ptrba[ 7] * b_val;
            res0_8 += ptrba[ 8] * b_val;
            res0_9 += ptrba[ 9] * b_val;
            res0_10 += ptrba[10] * b_val;
            res0_11 += ptrba[11] * b_val;
            res0_12 += ptrba[12] * b_val;
            res0_13 += ptrba[13] * b_val;
            res0_14 += ptrba[14] * b_val;
            res0_15 += ptrba[15] * b_val;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        res0_8 *= alpha;
        res0_9 *= alpha;
        res0_10 *= alpha;
        res0_11 *= alpha;
        res0_12 *= alpha;
        res0_13 *= alpha;
        res0_14 *= alpha;
        res0_15 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0[4] = res0_4;
        C0[5] = res0_5;
        C0[6] = res0_6;
        C0[7] = res0_7;
        C0[8] = res0_8;
        C0[9] = res0_9;
        C0[10] = res0_10;
        C0[11] = res0_11;
        C0[12] = res0_12;
        C0[13] = res0_13;
        C0[14] = res0_14;
        C0[15] = res0_15;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 16;
        ptrbb += temp;
        C0 = C0 + 16;
    }
    if (bm & 8) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[k];
            res0_0 += ptrba[0] * b_val;
            res0_1 += ptrba[1] * b_val;
            res0_2 += ptrba[2] * b_val;
            res0_3 += ptrba[3] * b_val;
            res0_4 += ptrba[4] * b_val;
            res0_5 += ptrba[5] * b_val;
            res0_6 += ptrba[6] * b_val;
            res0_7 += ptrba[7] * b_val;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0[4] = res0_4;
        C0[5] = res0_5;
        C0[6] = res0_6;
        C0[7] = res0_7;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 8;
        ptrbb += temp;
        C0 = C0 + 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[k];
            res0_0 += ptrba[0] * b_val;
            res0_1 += ptrba[1] * b_val;
            res0_2 += ptrba[2] * b_val;
            res0_3 += ptrba[3] * b_val;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4;
        ptrbb += temp;
        C0 = C0 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[k];
            res0_0 += ptrba[0] * b_val;
            res0_1 += ptrba[1] * b_val;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 = C0 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            res0_0 += ptrba[0] * ptrbb[k];
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp;
        ptrbb += temp;
        C0 = C0 + 1;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
