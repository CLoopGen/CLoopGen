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
    float *base_b = b + (ii - jj);  // Base pointer offset by index difference
    if ((ii >= jj) && (ii - jj < 4)) {
        for (k = 0; k < ii - jj; k++) {
            base_b[-k] = a1[k * lda];  // Reverse consecutive write using negative offset
        }
        base_b[0] = (1.F / a1[(ii - jj) * lda]);  // Store reciprocal at center point
    }
    if (ii - jj >= 4) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + lda);     // Indirect-like access via varying base strides
        *(b + 2) = *(a3 + 2*lda);
        *(b + 3) = *(a4 + 3*lda);   // Increasing stride per vector
    }
    a1 += 1;
    a2 += 1;
    a3 += 1;
    a4 += 1;
    b += 4;
    ii++;
}
}
