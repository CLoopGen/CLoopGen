#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bk;
extern float alpha;
extern float *bb;
extern BLASLONG i;
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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < bm / 16; i += 1) {
    ptrbb = bb;
    float accum0[16], accum1[16];
    for (int j = 0; j < 16; j++) {
        accum0[j] = 0;
        accum1[j] = 0;
    }
    temp = off + 2;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        for (int j = 0; j < 16; j += 2) {
            a0 = ptrba[j];
            a1 = ptrba[j+1];
            accum0[j]   += a0 * b0;
            accum1[j]   += a0 * b1;
            accum0[j+1] += a1 * b0;
            accum1[j+1] += a1 * b1;
        }
        ptrba += 16;
        ptrbb += 2;
    }
    for (int j = 0; j < 16; j++) {
        accum0[j] *= alpha;
        accum1[j] *= alpha;
    }
    for (int j = 0; j < 16; j++) {
        C0[j] = accum0[j];
        C1[j] = accum1[j];
    }
    temp = bk - off;
    temp -= 2;
    ptrba += temp * 16;
    ptrbb += temp * 2;
    C0 += 16;
    C1 += 16;
}
}
