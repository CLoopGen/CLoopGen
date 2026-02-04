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
        for (k = 0; k < ii - jj + 1; k++) {
            *(b + k) = *(a1 + k) * 2.F;
        }
        if (ii - jj >= 0) {
            *(b + ii - jj) = (1.F / (*(a1 + ii - jj) + 1e-6F));
        }
    }
    if (ii - jj >= 2) {
        *(b + 0) = *(a1 + 0) * *(a1 + 1);
    }
    b += 2;
    a1 += lda;
    ii += 2;
}
}
