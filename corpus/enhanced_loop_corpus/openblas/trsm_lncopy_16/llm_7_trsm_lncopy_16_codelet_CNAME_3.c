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
BLASLONG offset_a1, offset_a2;
for (i = 0; i < m; i++) {
    offset_a1 = (ii - jj) * lda;
    offset_a2 = 0;
    if ((ii >= jj) && (ii - jj < 2)) {
        for (k = 0; k < ii - jj; k++) {
            *(b + k) = *(a1 + k * lda);
        }
        *(b + ii - jj) = (1.F / (*(a1 + offset_a1)));
    }
    if (ii - jj >= 2) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + offset_a2);
    }
    a1++;
    a2++;
    b += 2;
    ii++;
}
}
