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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 4)) {
        for (k = 0; k < ii - jj; k++) {
            *(b + k) = *(a1 + k * lda) + *(a2 + k * lda);
        }
        float inv_val = *(a1 + (ii - jj) * lda);
        *(b + ii - jj) = (inv_val != 0.F) ? (1.F / inv_val) : 0.F;
    }
    if (ii - jj >= 4) {
        *(b + 0) = *(a1 + 0) + *(a2 + 0);
        *(b + 1) = *(a2 + 0) - *(a1 + 0);
        *(b + 2) = *(a3 + 0) * 2.F;
        *(b + 3) = *(a4 + 0) / 2.F;
    }
    a1 += 2;
    a2 += 2;
    a3 += 2;
    a4 += 2;
    b += 8;
    ii += 2;
}
}
