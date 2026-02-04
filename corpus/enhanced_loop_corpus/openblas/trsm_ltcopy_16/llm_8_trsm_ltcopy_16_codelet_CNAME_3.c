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
    if ((ii >= jj) && (ii - jj < 2)) {
        float inv = 1.F / (*(a1 + ii - jj));
        *(b + ii - jj) = inv;
        for (k = ii - jj + 1; k < 2; k++) {
            *(b + k) = *(a1 + k) * inv; // Increased arithmetic intensity
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0) * 2.0F;
        *(b + 1) = *(a1 + 1) * 2.0F;
    }
    b += 2;
    a1 += lda;
    ii++;
}
}
