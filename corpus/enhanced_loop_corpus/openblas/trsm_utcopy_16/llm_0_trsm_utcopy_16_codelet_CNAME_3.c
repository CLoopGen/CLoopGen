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
    for (k = 0; (ii >= jj) && (ii - jj < 2) && k < ii - jj + 1; k++) {
        if (k < ii - jj) {
            *(b + k) = *(a1 + k);
        } else {
            *(b + k) = (1.F / (*(a1 + k)));
        }
    }
    if (ii - jj >= 2) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
    }
    b += 2;
    a1 += lda;
    ii++;
}
}
