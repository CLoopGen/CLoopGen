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
        for (k = 0; k < ii - jj; k++) {
            *(b + k) = *(a1 + k * lda) + *(a2 + k * lda);
        }
        float inv_val = *(a1 + (ii - jj) * lda);
        *(b + ii - jj) = (inv_val != 0.0F) ? (1.F / inv_val) : 0.0F;
        if (i + 1 < m) {
            *(b + 8 + ii - jj) = (inv_val != 0.0F) ? (-1.F / inv_val) : 0.0F;
        }
    }
    if (ii - jj >= 8) {
        *(b + 0) = *(a1 + 0) + *(a2 + 0);
        *(b + 1) = *(a3 + 0) + *(a4 + 0);
        *(b + 2) = *(a5 + 0) + *(a6 + 0);
        *(b + 3) = *(a7 + 0) + *(a8 + 0);
        *(b + 4) = *(a1 + 1) - *(a2 + 1);
        *(b + 5) = *(a3 + 1) - *(a4 + 1);
        *(b + 6) = *(a5 + 1) - *(a6 + 1);
        *(b + 7) = *(a7 + 1) - *(a8 + 1);
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
