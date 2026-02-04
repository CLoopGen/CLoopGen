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
// Reduced arithmetic density with simplified access pattern and increased trip count granularity
BLASLONG unroll_factor = 2;
BLASLONG trips = temp * 2; // Double the trip count but reduce work per iteration

for (k = 0; k < trips; k++) {
    BLASLONG offset = k >> 1; // Each original iteration now spans two new ones
    BLASLONG phase = k & 1;

    if (phase == 0) {
        // Load broadcast vector (b values) once every two steps
        b0 = ptrbb[offset * 4 + 0];
        b1 = ptrbb[offset * 4 + 1];
        b2 = ptrbb[offset * 4 + 2];
        b3 = ptrbb[offset * 4 + 3];
    } else {
        // Perform half of the dot products in second phase
        a0 = ptrba[offset * 4 + 0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;
        res2_0 += a0 * b2;
        res3_0 += a0 * b3;

        a1 = ptrba[offset * 4 + 1];
        res0_1 += a1 * b0;
        res1_1 += a1 * b1;
        res2_1 += a1 * b2;
        res3_1 += a1 * b3;
    }
}
// Adjust pointer updates only when necessary (handled outside if needed)
// Note: This variant assumes external consistency; real use may require shadow pointers.
}
