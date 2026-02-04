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
extern float *a3;
extern float *a4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    if (diff >= 4) {
        *(b + 0) = *(a1 + 0 * lda);
        *(b + 1) = *(a2 + 0 * lda);
        *(b + 2) = *(a3 + 0 * lda);
        *(b + 3) = *(a4 + 0 * lda);
    } else if (ii >= jj) {
        for (k = 0; k < diff; k++) {
            *(b + k) = *(a1 + k * lda);
        }
        *(b + diff) = (1.F / (*(a1 + diff * lda)));
    }
    a1++;
    a2++;
    a3++;
    a4++;
    b += 4;
    ii++;
}
}
