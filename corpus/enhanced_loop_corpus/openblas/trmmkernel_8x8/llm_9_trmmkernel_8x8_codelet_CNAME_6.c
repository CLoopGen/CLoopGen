#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res1_0;
extern float res2_0;
extern float res3_0;
extern float a0;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG unroll_factor = 4;
    BLASLONG remainder = temp % unroll_factor;
    BLASLONG main_loop_count = temp - remainder;

    for (k = 0; k < main_loop_count; k += unroll_factor) {
        float a, b_vals[4];

        // Unrolled iteration 1
        b_vals[0] = ptrbb[0]; b_vals[1] = ptrbb[1]; b_vals[2] = ptrbb[2]; b_vals[3] = ptrbb[3];
        a = ptrba[0];
        res0_0 += a * b_vals[0];
        res1_0 += a * b_vals[1];
        res2_0 += a * b_vals[2];
        res3_0 += a * b_vals[3];

        // Unrolled iteration 2
        b_vals[0] = ptrbb[4]; b_vals[1] = ptrbb[5]; b_vals[2] = ptrbb[6]; b_vals[3] = ptrbb[7];
        a = ptrba[1];
        res0_0 += a * b_vals[0];
        res1_0 += a * b_vals[1];
        res2_0 += a * b_vals[2];
        res3_0 += a * b_vals[3];

        // Unrolled iteration 3
        b_vals[0] = ptrbb[8]; b_vals[1] = ptrbb[9]; b_vals[2] = ptrbb[10]; b_vals[3] = ptrbb[11];
        a = ptrba[2];
        res0_0 += a * b_vals[0];
        res1_0 += a * b_vals[1];
        res2_0 += a * b_vals[2];
        res3_0 += a * b_vals[3];

        // Unrolled iteration 4
        b_vals[0] = ptrbb[12]; b_vals[1] = ptrbb[13]; b_vals[2] = ptrbb[14]; b_vals[3] = ptrbb[15];
        a = ptrba[3];
        res0_0 += a * b_vals[0];
        res1_0 += a * b_vals[1];
        res2_0 += a * b_vals[2];
        res3_0 += a * b_vals[3];

        ptrba += 4;
        ptrbb += 16;
    }

    // Handle remaining iterations
    for (; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        b2 = ptrbb[2];
        b3 = ptrbb[3];
        a0 = ptrba[0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;
        res2_0 += a0 * b2;
        res3_0 += a0 * b3;
        ptrba++;
        ptrbb += 4;
    }
}
