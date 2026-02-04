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
    if ((ii >= jj) && (ii - jj < 4)) {
        for (k = 0; k < ii - jj; k++) {
            *(b + k) = *(a1 + k);
        }
        *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
    }
    if (ii - jj >= 4) {
        for (BLASLONG unroll_factor = 0; unroll_factor < 4; unroll_factor++) {
            *(b + unroll_factor) = *(a1 + unroll_factor);
        }
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
