#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res1_0;
extern float res1_1;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < temp; k += 2) {
        if (k + 1 < temp) {
            // First iteration of unrolled pair
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
            float *next_ba = ptrba + 2;
            float *next_bb = ptrbb + 2;

            // Second iteration
            b0 = next_bb[0];
            b1 = next_bb[1];
            a0 = next_ba[0];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            a1 = next_ba[1];
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;

            ptrba = next_ba + 2;
            ptrbb = next_bb + 2;
        } else {
            // Handle leftover element
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 2;
        }
    }
}
