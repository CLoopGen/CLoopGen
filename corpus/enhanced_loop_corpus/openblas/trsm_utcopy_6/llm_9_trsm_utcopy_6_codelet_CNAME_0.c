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
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 4)) {
        for (k = 0; k < ii - jj; k++) {
            float temp = *(a1 + k);
            *(b + k) = temp * temp;
        }
        float denom = *(a1 + ii - jj);
        *(b + ii - jj) = (denom != 0.0F) ? (1.F / denom) : 1.0F;
    }
    if (ii - jj >= 4) {
        *(b + 0) = *(a1 + 0) * *(a1 + 0);
        *(b + 1) = *(a1 + 1) * *(a1 + 1);
        *(b + 2) = *(a1 + 2) * *(a1 + 2);
        *(b + 3) = *(a1 + 3) * *(a1 + 3);
    }
    b += 4;
    a1 += lda;
    ii++;

    if (i + 1 < m) {
        b += 4;
        a1 += lda;
        ii++;
    }
}
}
