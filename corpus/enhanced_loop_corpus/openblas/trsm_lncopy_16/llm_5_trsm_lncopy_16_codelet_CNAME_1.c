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
extern float *a5;
extern float *a6;
extern float *a7;
extern float *a8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG execute_small = (ii >= jj) && (ii - jj < 8);
    BLASLONG execute_large = (ii - jj >= 8);

    if (execute_small) {
        BLASLONG diff = ii - jj;
        for (k = 0; k <= diff; k++) {
            if (k < diff) {
                *(b + k) = *(a1 + k * lda);
            } else {
                *(b + k) = (1.F / (*(a1 + k * lda)));
            }
        }
    }

    if (!execute_small && execute_large) {
        *(b + 0) = *a1;
        *(b + 1) = *a2;
        *(b + 2) = *a3;
        *(b + 3) = *a4;
        *(b + 4) = *a5;
        *(b + 5) = *a6;
        *(b + 6) = *a7;
        *(b + 7) = *a8;
    }

    a1 += 1;
    a2 += 1;
    a3 += 1;
    a4 += 1;
    a5 += 1;
    a6 += 1;
    a7 += 1;
    a8 += 1;
    b += 8;
    ii++;
}
}
