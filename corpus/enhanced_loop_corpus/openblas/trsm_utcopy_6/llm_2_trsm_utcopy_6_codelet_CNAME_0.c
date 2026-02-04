#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern float *a1;
extern BLASLONG k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    if ((ii >= jj) && (ii - jj < 4)) {
        for (k = 0; k < ii - jj; k++) {
            b[k] = a1[k * lda]; // Changed access pattern: strided read from a1 using lda stride, direct write to b
        }
        b[ii - jj] = (1.F / a1[(ii - jj) * lda]); // Strided access for reciprocal element
    }
    if (ii - jj >= 4) {
        b[0] = a1[0 * lda];
        b[1] = a1[1 * lda];
        b[2] = a1[2 * lda];
        b[3] = a1[3 * lda];
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
