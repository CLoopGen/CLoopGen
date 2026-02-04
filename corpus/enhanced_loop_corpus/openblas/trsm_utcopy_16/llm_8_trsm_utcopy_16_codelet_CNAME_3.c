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
    if ((ii >= jj) && (ii - jj < 3)) {
        for (k = 0; k < ii - jj + 1; k++) {
            if (k == ii - jj) {
                *(b + k) = (1.F / (*(a1 + k) + 1e-6F));
            } else {
                *(b + k) = *(a1 + k) * 2.F;
            }
        }
    }
    if (ii - jj >= 3) {
        *(b + 0) = *(a1 + 0) * 2.F;
        *(b + 1) = *(a1 + 1) * 2.F;
        *(b + 2) = *(a1 + 2) * 2.F;
    }
    b += 3;
    a1 += lda;
    ii++;
}
}
