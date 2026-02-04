#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < temp; k++) {
    // Consecutive memory access with local array staging to change access pattern
    float bb_local[4];
    float ba_local[4];
    for (BLASLONG i = 0; i < 4; i++) {
        bb_local[i] = ptrbb[i];
        ba_local[i] = ptrba[i];
    }
    b0 = bb_local[0];
    b1 = bb_local[1];
    b2 = bb_local[2];
    b3 = bb_local[3];
    a0 = ba_local[0];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    res2_0 += a0 * b2;
    res3_0 += a0 * b3;
    a1 = ba_local[1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
    res2_1 += a1 * b2;
    res3_1 += a1 * b3;
    a0 = ba_local[2];
    res0_2 += a0 * b0;
    res1_2 += a0 * b1;
    res2_2 += a0 * b2;
    res3_2 += a0 * b3;
    a1 = ba_local[3];
    res0_3 += a1 * b0;
    res1_3 += a1 * b1;
    res2_3 += a1 * b2;
    res3_3 += a1 * b3;
    ptrba += 4;
    ptrbb += 4;
}
}
