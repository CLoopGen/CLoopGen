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
for (i = 0; i < m; i++) {
    if ((ii >= jj) && (ii - jj < 4)) {
        BLASLONG offset = ii - jj;
        *(b + 0) = (1.F / (*(a1 + offset * lda)));
        for (k = 1; k < 4 - offset; k++) {
            *(b + k) = *(a1 + (offset + k) * lda);
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0 * lda);
        *(b + 1) = *(a2 + 0 * lda);
        *(b + 2) = *(a3 + 0 * lda);
        *(b + 3) = *(a4 + 0 * lda);
    }
    a1 += lda;
    a2 += lda;
    a3 += lda;
    a4 += lda;
    b += 4;
    ii++;
}
}
