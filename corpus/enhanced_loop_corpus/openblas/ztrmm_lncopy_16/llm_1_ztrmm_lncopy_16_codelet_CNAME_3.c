#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii += 2) { // Increase loop stride and nest inner iteration to preserve semantics
        for (BLASLONG j = 0; j < 2 && (ii + j) < i; j++) {
            BLASLONG offset_b = (ii + j) * 16;
            float *b_local = b + offset_b;
            float *a1 = a01 + j * 2;
            float *a2 = a02 + j * 2;
            float *a3 = a03 + j * 2;
            float *a4 = a04 + j * 2;
            float *a5 = a05 + j * 2;
            float *a6 = a06 + j * 2;
            float *a7 = a07 + j * 2;
            float *a8 = a08 + j * 2;

            b_local[0] = *(a1 + 0);
            b_local[1] = *(a1 + 1);
            b_local[2] = *(a2 + 0);
            b_local[3] = *(a2 + 1);
            b_local[4] = *(a3 + 0);
            b_local[5] = *(a3 + 1);
            b_local[6] = *(a4 + 0);
            b_local[7] = *(a4 + 1);
            b_local[8] = *(a5 + 0);
            b_local[9] = *(a5 + 1);
            b_local[10] = *(a6 + 0);
            b_local[11] = *(a6 + 1);
            b_local[12] = *(a7 + 0);
            b_local[13] = *(a7 + 1);
            b_local[14] = *(a8 + 0);
            b_local[15] = *(a8 + 1);
        }
        // Update global pointers after processing two iterations
        a01 += 4;
        a02 += 4;
        a03 += 4;
        a04 += 4;
        a05 += 4;
        a06 += 4;
        a07 += 4;
        a08 += 4;
        b += 32;
    }
}
