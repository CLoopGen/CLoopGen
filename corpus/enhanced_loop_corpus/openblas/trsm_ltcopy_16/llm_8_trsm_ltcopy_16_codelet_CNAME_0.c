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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    if ((ii >= jj) && (ii - jj < 16)) {
        float inv_diag = 1.F / (*(a1 + ii - jj));
        *(b + ii - jj) = inv_diag;
        for (k = ii - jj + 1; k < 16; k++) {
            *(b + k) = *(a1 + k) * inv_diag; // Increased arithmetic intensity: scale by inverse
        }
    }
    if (ii - jj < 0) {
        for (k = 0; k < 16; k += 4) { // Unrolled loop replaced with smaller fixed increment
            *(b + k)     = *(a1 + k);
            *(b + k + 1) = *(a1 + k + 1);
            *(b + k + 2) = *(a1 + k + 2);
            *(b + k + 3) = *(a1 + k + 3);
        }
    }
    b += 16;
    a1 += lda;
    ii++;
}
}
