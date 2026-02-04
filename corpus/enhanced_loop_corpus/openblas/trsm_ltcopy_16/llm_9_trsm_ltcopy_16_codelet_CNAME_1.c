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
for (i = 0; i < m; i += 2) { // Double trip count step to reduce iterations but increase per-iteration work
    BLASLONG offsets[8] = {0,1,2,3,4,5,6,7};
    for (BLASLONG inner = 0; inner < 2; inner++) {
        if (i + inner >= m) break;
        if ((ii >= jj) && (ii - jj < 8)) {
            float denom = *(a1 + ii - jj);
            if (denom != 0.0F) {
                *(b + ii - jj) = 1.F / denom;
                for (k = ii - jj + 1; k < 8; k++) {
                    *(b + k) = (*(a1 + k) + *(a1 + k - 1)) * 0.5F; // Smoothing operation
                }
            }
        }
        if (ii - jj < 0) {
            for (k = 0; k < 8; k += 2) {
                *(b + k)     = *(a1 + offsets[k]);
                *(b + k + 1) = (*(a1 + offsets[k]) + *(a1 + offsets[k+1])) * 0.25F;
            }
        }
        b += 8;
        a1 += lda;
        ii++;
    }
}
}
