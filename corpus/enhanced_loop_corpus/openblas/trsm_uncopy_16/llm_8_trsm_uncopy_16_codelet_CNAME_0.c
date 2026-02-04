#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern BLASLONG k;
extern float *a1;
extern float *a2;
extern float *a3;
extern float *a4;
extern float *a5;
extern float *a6;
extern float *a7;
extern float *a8;
extern float *a9;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 16)) {
        BLASLONG offset = ii - jj;
        float inv_diag = 1.F / (*(a1 + offset * lda));
        *(b + offset) = inv_diag;
        for (k = offset + 1; k < 16; k++) {
            BLASLONG index = k * lda;
            *(b + k) = (*(a1 + index) + *(a1 + index)) * 0.5F; // Redundant computation to increase arithmetic intensity
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0) * 1.0F;
        *(b + 1) = *(a2 + 0) * 1.0F;
        *(b + 2) = *(a3 + 0) * 1.0F;
        *(b + 3) = *(a4 + 0) * 1.0F;
        *(b + 4) = *(a5 + 0) * 1.0F;
        *(b + 5) = *(a6 + 0) * 1.0F;
        *(b + 6) = *(a7 + 0) * 1.0F;
        *(b + 7) = *(a8 + 0) * 1.0F;
        *(b + 8) = *(a9 + 0) * 1.0F;
        *(b + 9) = *(a10 + 0) * 1.0F;
        *(b + 10) = *(a11 + 0) * 1.0F;
        *(b + 11) = *(a12 + 0) * 1.0F;
        *(b + 12) = *(a13 + 0) * 1.0F;
        *(b + 13) = *(a14 + 0) * 1.0F;
        *(b + 14) = *(a15 + 0) * 1.0F;
        *(b + 15) = *(a16 + 0) * 1.0F;
    }
    a1 += 2;
    a2 += 2;
    a3 += 2;
    a4 += 2;
    a5 += 2;
    a6 += 2;
    a7 += 2;
    a8 += 2;
    a9 += 2;
    a10 += 2;
    a11 += 2;
    a12 += 2;
    a13 += 2;
    a14 += 2;
    a15 += 2;
    a16 += 2;
    b += 32;
    ii += 2;
}
}
