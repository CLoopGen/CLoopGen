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
BLASLONG prev_ii = ii;
for (i = 0; i < m; i++) {
    BLASLONG delta = prev_ii - jj;
    if ((prev_ii >= jj) && (delta < 4)) {
        for (k = 0; k <= delta; k++) {
            if (k < delta) {
                *(b + k) = *(a1 + k * lda);
            } else {
                *(b + k) = (1.F / (*(a1 + k * lda)));
            }
        }
    }
    if (delta >= 4) {
        *(b + 0) = *(a1 + 0 * lda);
        *(b + 1) = *(a1 + 1 * lda);
        *(b + 2) = *(a1 + 2 * lda);
        *(b + 3) = *(a1 + 3 * lda);
    }
    prev_ii++;
    a1 += 1;
    a2 += 1;
    a3 += 1;
    a4 += 1;
    b += 4;
}
ii = prev_ii;
}
