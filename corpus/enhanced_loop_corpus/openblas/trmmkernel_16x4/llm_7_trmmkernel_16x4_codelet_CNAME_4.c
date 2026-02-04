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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_res0_0 = res0_0;
    float local_res0_1 = res0_1;
    float local_res0_2 = res0_2;
    float local_res0_3 = res0_3;
    float local_res1_0 = res1_0;
    float local_res1_1 = res1_1;
    float local_res1_2 = res1_2;
    float local_res1_3 = res1_3;

    // Remove loop-carried dependencies by using local accumulators
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];

        a0 = ptrba[0];
        local_res0_0 = local_res0_0 + a0 * b0;
        local_res1_0 = local_res1_0 + a0 * b1;

        a1 = ptrba[1];
        local_res0_1 = local_res0_1 + a1 * b0;
        local_res1_1 = local_res1_1 + a1 * b1;

        a0 = ptrba[2];
        local_res0_2 = local_res0_2 + a0 * b0;
        local_res1_2 = local_res1_2 + a0 * b1;

        a1 = ptrba[3];
        local_res0_3 = local_res0_3 + a1 * b0;
        local_res1_3 = local_res1_3 + a1 * b1;

        ptrba = ptrba + 4;
        ptrbb = ptrbb + 2;
    }

    // Reintroduce final values after loop (no loop-carried dep in res vars)
    res0_0 = local_res0_0;
    res1_0 = local_res1_0;
    res0_1 = local_res0_1;
    res1_1 = local_res1_1;
    res0_2 = local_res0_2;
    res1_2 = local_res1_2;
    res0_3 = local_res0_3;
    res1_3 = local_res1_3;
}
