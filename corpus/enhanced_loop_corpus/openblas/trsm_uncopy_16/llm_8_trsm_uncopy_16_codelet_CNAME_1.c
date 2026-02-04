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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 8)) {
        BLASLONG offset = ii - jj;
        float inv_diag = 1.F / (*(a1 + offset * lda));
        *(b + offset) = inv_diag;
        for (k = offset + 1; k < 8; k++) {
            *(b + k) = *(a1 + k * lda) * inv_diag;
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0) + *(a2 + 0);
        *(b + 1) = *(a3 + 0) + *(a4 + 0);
        *(b + 2) = *(a5 + 0) + *(a6 + 0);
        *(b + 3) = *(a7 + 0) + *(a8 + 0);
        *(b + 4) = *(a1 + 0) - *(a2 + 0);
        *(b + 5) = *(a3 + 0) - *(a4 + 0);
        *(b + 6) = *(a5 + 0) - *(a6 + 0);
        *(b + 7) = *(a7 + 0) - *(a8 + 0);
    } else {
        for (k = 0; k < 8; k++) {
            if (k % 2 == 0) *(b + k) += 0.5F;
            else            *(b + k) -= 0.5F;
        }
    }
    a1 += 2;
    a2 += 2;
    a3 += 2;
    a4 += 2;
    a5 += 2;
    a6 += 2;
    a7 += 2;
    a8 += 2;
    b += 16;
    ii += 2;
}
}
