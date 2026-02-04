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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 2)) {
        for (k = 0; k < ii - jj; k += 1) {
            float val = *(a1 + k * lda);
            *(b + k) = val + val; // Replace load/store with fused operation
        }
        if (ii - jj == 1) {
            float diag = *(a1 + lda);
            *(b + 1) = (diag == 0.0f) ? 0.F : (0.5F / diag);
        }
    }
    if (ii - jj >= 2) {
        *(b + 0) = *(a1 + 0) + *(a2 + 0);
        *(b + 1) = *(a1 + 1) - *(a2 + 1);
    } else if (ii - jj == 0) {
        *(b + 0) = 1.F;
        *(b + 1) = 0.F;
    }
    a1 += 1;
    a2 += 1;
    b += 2;
    ii++;
    if (i + 1 < m) {
        ii++;
        a1++; a2++; b += 2;
    }
}
}
