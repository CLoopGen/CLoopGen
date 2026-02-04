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
for (i = 0; i < m; i++) {
    BLASLONG offset_b = (b - &b[0]); // Base offset for b
    BLASLONG offset_a1 = (a1 - &a1[0]); // Base offset for a1
    BLASLONG offset_a2 = (a2 - &a2[0]); // Base offset for a2

    if ((ii >= jj) && (ii - jj < 2)) {
        *(b + ii - jj) = (1.F / (*(a1 + (ii - jj) * lda)));
        for (k = ii - jj + 1; k < 2; k++) {
            b[offset_b + k] = a1[offset_a1 + k * lda]; // Consecutive base-relative access
        }
    }
    if (ii - jj < 0) {
        b[offset_b + 0] = a1[offset_a1 + 0];
        b[offset_b + 1] = a2[offset_a2 + 0];
    }
    a1++;
    a2++;
    b += 2;
    ii++;
}
}
