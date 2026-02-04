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
    for (k = 0; k < temp; k += 2) {
        if (k + 1 < temp) {
            // First iteration of pair
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                a0 = ptrba[0];
                res0_0 += a0 * b0;
                res1_0 += a0 * b1;
                a1 = ptrba[1];
                res0_1 += a1 * b0;
                res1_1 += a1 * b1;
                a0 = ptrba[2];
                res0_2 += a0 * b0;
                res1_2 += a0 * b1;
                a1 = ptrba[3];
                res0_3 += a1 * b0;
                res1_3 += a1 * b1;
                float* ptrba_local = ptrba;
                float* ptrbb_local = ptrbb;
                ptrba_local += 4;
                ptrbb_local += 2;

                // Second iteration of pair
                b0 = ptrbb_local[0];
                b1 = ptrbb_local[1];
                a0 = ptrba_local[0];
                res0_0 += a0 * b0;
                res1_0 += a0 * b1;
                a1 = ptrba_local[1];
                res0_1 += a1 * b0;
                res1_1 += a1 * b1;
                a0 = ptrba_local[2];
                res0_2 += a0 * b0;
                res1_2 += a0 * b1;
                a1 = ptrba_local[3];
                res0_3 += a1 * b0;
                res1_3 += a1 * b1;

                ptrba = ptrba_local + 4;
                ptrbb = ptrbb_local + 2;
            }
        } else {
            // Handle odd final iteration
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
            a0 = ptrba[2];
            res0_2 += a0 * b0;
            res1_2 += a0 * b1;
            a1 = ptrba[3];
            res0_3 += a1 * b0;
            res1_3 += a1 * b1;
            ptrba = ptrba + 4;
            ptrbb = ptrbb + 2;
        }
    }
}
