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
BLASLONG stride = lda * 2; // Strided access pattern with larger step
for (i = 0; i < m; i++) {
    if ((ii >= jj) && (ii - jj < 2)) {
        BLASLONG idx = (ii - jj);
        *(b + idx) = (1.F / (*(a1 + idx * lda)));
        for (k = ii - jj + 1; k < 2; k++) {
            *(b + k) = *(a1 + k * stride); // Strided access using doubled lda
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0 * stride);
        *(b + 1) = *(a2 + 0 * stride);
    }
    a1 += 1;
    a2 += 1;
    b += 2;
    ii++;
}
}
