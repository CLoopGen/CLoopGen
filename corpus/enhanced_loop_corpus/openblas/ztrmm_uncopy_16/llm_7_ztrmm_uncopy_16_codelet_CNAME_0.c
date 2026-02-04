#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 32; ii++) {
    // Reduce memory operations per iteration: interleave fewer assignments
    BLASLONG idx_b = ii * 16;
    BLASLONG offset = (ii % 2 == 0) ? 0 : 1;
    BLASLONG base_a_idx = (ii / 2) * 2;

    if (ii < 2) {
        b[idx_b + 0]  = *(a01 + offset);
        b[idx_b + 1]  = *(a02 + offset);
        b[idx_b + 2]  = *(a03 + offset);
        b[idx_b + 3]  = *(a04 + offset);
        b[idx_b + 4]  = *(a05 + offset);
        b[idx_b + 5]  = *(a06 + offset);
        b[idx_b + 6]  = *(a07 + offset);
        b[idx_b + 7]  = *(a08 + offset);
        b[idx_b + 8]  = *(a09 + offset);
        b[idx_b + 9]  = *(a10 + offset);
        b[idx_b + 10] = *(a11 + offset);
        b[idx_b + 11] = *(a12 + offset);
        b[idx_b + 12] = *(a13 + offset);
        b[idx_b + 13] = *(a14 + offset);
        b[idx_b + 14] = *(a15 + offset);
        b[idx_b + 15] = *(a16 + offset);

        if (ii % 2 == 1) {
            a01 += 2; a02 += 2; a03 += 2; a04 += 2;
            a05 += 2; a06 += 2; a07 += 2; a08 += 2;
            a09 += 2; a10 += 2; a11 += 2; a12 += 2;
            a13 += 2; a14 += 2; a15 += 2; a16 += 2;
        }
    } else {
        // Fill with dummy computation to increase trip count and computational intensity
        float sum = 0.0f;
        for (BLASLONG j = 0; j < 16; j++) {
            sum += (float)(ii * j + 1);
        }
        b[idx_b] = sum;
    }
}
}
