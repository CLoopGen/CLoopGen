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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
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
for (i = 0; i < bm / 8; i += 1) {
    BLASLONG base_bb = i * 32; // Base offset into bb for consecutive block access
    ptrbb = bb + base_bb;
    res0_0 = 0;
    res0_1 = 0;
    res0_2 = 0;
    res0_3 = 0;
    res0_4 = 0;
    res0_5 = 0;
    res0_6 = 0;
    res0_7 = 0;
    res1_0 = 0;
    res1_1 = 0;
    res1_2 = 0;
    res1_3 = 0;
    res1_4 = 0;
    res1_5 = 0;
    res1_6 = 0;
    res1_7 = 0;
    res2_0 = 0;
    res2_1 = 0;
    res2_2 = 0;
    res2_3 = 0;
    res2_4 = 0;
    res2_5 = 0;
    res2_6 = 0;
    res2_7 = 0;
    res3_0 = 0;
    res3_1 = 0;
    res3_2 = 0;
    res3_3 = 0;
    res3_4 = 0;
    res3_5 = 0;
    res3_6 = 0;
    res3_7 = 0;
    temp = off + 4;
    for (k = 0; k < temp; k++) {
        // Load B values using direct indexed access with fixed stride
        b0 = *(ptrbb + (k << 2) + 0);
        b1 = *(ptrbb + (k << 2) + 1);
        b2 = *(ptrbb + (k << 2) + 2);
        b3 = *(ptrbb + (k << 2) + 3);
        // Load A values in a tightly packed, consecutive pattern from ptrba
        BLASLONG a_idx = k * 8;
        a0 = ptrba[a_idx + 0]; res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
        a1 = ptrba[a_idx + 1]; res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
        a0 = ptrba[a_idx + 2]; res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
        a1 = ptrba[a_idx + 3]; res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;
        a0 = ptrba[a_idx + 4]; res0_4 += a0 * b0; res1_4 += a0 * b1; res2_4 += a0 * b2; res3_4 += a0 * b3;
        a1 = ptrba[a_idx + 5]; res0_5 += a1 * b0; res1_5 += a1 * b1; res2_5 += a1 * b2; res3_5 += a1 * b3;
        a0 = ptrba[a_idx + 6]; res0_6 += a0 * b0; res1_6 += a0 * b1; res2_6 += a0 * b2; res3_6 += a0 * b3;
        a1 = ptrba[a_idx + 7]; res0_7 += a1 * b0; res1_7 += a1 * b1; res2_7 += a1 * b2; res3_7 += a1 * b3;
    }
    // Scale results by alpha
    res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
    res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
    res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
    res1_4 *= alpha; res1_5 *= alpha; res1_6 *= alpha; res1_7 *= alpha;
    res2_0 *= alpha; res2_1 *= alpha; res2_2 *= alpha; res2_3 *= alpha;
    res2_4 *= alpha; res2_5 *= alpha; res2_6 *= alpha; res2_7 *= alpha;
    res3_0 *= alpha; res3_1 *= alpha; res3_2 *= alpha; res3_3 *= alpha;
    res3_4 *= alpha; res3_5 *= alpha; res3_6 *= alpha; res3_7 *= alpha;
    // Store results to output arrays using pointer arithmetic
    for (BLASLONG j = 0; j < 8; j++) {
        C0[j] = *((float*)&res0_0 + j);
        C1[j] = *((float*)&res1_0 + j);
        C2[j] = *((float*)&res2_0 + j);
        C3[j] = *((float*)&res3_0 + j);
    }
    temp = bk - off;
    temp -= 4;
    ptrba += temp * 8;
    ptrbb += temp * 4;
    C0 += 8;
    C1 += 8;
    C2 += 8;
    C3 += 8;
}
}
