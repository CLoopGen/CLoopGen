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
        BLASLONG offset = ii - jj;
        float inv_pivot = 1.F / (*(a1 + offset));
        *(b + 0) = inv_pivot;
        for (k = 1; k < 8 - offset; k++) {
            *(b + k) = *(a1 + offset + k);
        }
        for (k = 8 - offset; k < 8; k++) {
            *(b + k) = 0.0f; // Fill remainder to maintain memory footprint
        }
    }
    if (ii - jj < 0) {
        // Unroll and access a1 consecutively with fixed offset from base
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
        *(b + 2) = *(a1 + 2);
        *(b + 3) = *(a1 + 3);
        *(b + 4) = *(a1 + 4);
        *(b + 5) = *(a1 + 5);
        *(b + 6) = *(a1 + 6);
        *(b + 7) = *(a1 + 7);
    }
    b += 8;
    a1 += lda;
    ii++;
}
}
