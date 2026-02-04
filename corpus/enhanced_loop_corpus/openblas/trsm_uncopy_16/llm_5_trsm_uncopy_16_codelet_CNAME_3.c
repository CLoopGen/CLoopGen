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
for (i = 0; i < m; i++) {
    int cond1 = (ii >= jj) && (ii - jj < 2);
    int cond2 = (ii - jj < 0);

    if (cond1) {
        *(b + ii - jj) = (1.F / (*(a1 + (ii - jj) * lda)));
        for (k = ii - jj + 1; k < 2; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    }

    if (!cond1 && cond2) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + 0);
    }

    if (!cond1 && !cond2) {
        *(b + 0) = 0.0F;
        *(b + 1) = 0.0F;
    }

    a1++;
    a2++;
    b += 2;
    ii++;
}
}
