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
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 1)) {
        for (k = 0; k < ii - jj; k += 1) {
            float temp = *(a1 + k);
            *(b + k) = temp * temp;
        }
        if (ii - jj >= 0) {
            float denom = *(a1 + ii - jj);
            *(b + ii - jj) = (denom != 0.F) ? (2.F / denom) : 1.F;
        }
    }
    if (ii - jj >= 1) {
        *(b + 0) = *(a1 + 0) + *(a1 + 0);
    }
    b += 1;
    a1 += lda;
    ii++;
    if (i + 1 < m) {
        b += 1;
        a1 += lda;
        ii++;
    }
}
}
