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
    if ((ii >= jj) && (ii - jj < 8)) {
        for (k = 0; k < ii - jj; k++) {
            *(b + k) = *(a1 + k) * 2.0F;
        }
        if (ii - jj >= 0) {
            *(b + ii - jj) = (1.F / (*(a1 + ii - jj) + 1e-6F));
        }
    }
    if (ii - jj >= 8) {
        for (k = 0; k < 4; k++) {
            *(b + k) = *(a1 + k) * 2.0F;
        }
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
