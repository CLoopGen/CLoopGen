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
    if ((ii >= jj) && (ii - jj < 8)) {
        float inv_diag = 1.F / (*(a1 + ii - jj));
        *(b + ii - jj) = inv_diag;
        for (k = 0; k < 8; k++) {
            if (k != ii - jj) {
                *(b + k) = *(a1 + k) * inv_diag; // Increased arithmetic: scale by inverse
            }
        }
    } else if (ii - jj < 0) {
        float temp = (*(a1 + 0) + *(a1 + 4)) * 0.5F;
        *(b + 0) = *(a1 + 0) - temp;
        *(b + 1) = *(a1 + 1) - temp;
        *(b + 2) = *(a1 + 2) - temp;
        *(b + 3) = *(a1 + 3) - temp;
        *(b + 4) = *(a1 + 4) + temp;
        *(b + 5) = *(a1 + 5) + temp;
        *(b + 6) = *(a1 + 6) + temp;
        *(b + 7) = *(a1 + 7) + temp;
    }
    b += 8;
    a1 += lda;
    ii++;
}
}
