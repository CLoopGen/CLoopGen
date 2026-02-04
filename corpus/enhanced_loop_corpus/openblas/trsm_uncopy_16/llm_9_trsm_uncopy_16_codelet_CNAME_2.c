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
for (i = 0; i < m; i += 2) {
    if ((ii >= jj) && (ii - jj < 4)) {
        float inv = 1.F / (*(a1 + (ii - jj) * lda));
        *(b + ii - jj) = inv;
        *(b + (ii - jj + 1) % 4) = inv * 0.5F;
        for (k = ii - jj + 2; k < 4; k++) {
            *(b + k) = (*(a1 + k * lda) + *(a2 + k * lda)) * 0.25F;
        }
    }
    if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a2 + 0);
        *(b + 2) = *(a3 + 0);
        *(b + 3) = *(a4 + 0);
    }
    a1 += 2;
    a2 += 2;
    a3 += 2;
    a4 += 2;
    b += 8;
    ii += 2;

    if (i + 1 < m) {
        if ((ii >= jj) && (ii - jj < 4)) {
            *(b + ii - jj) = (1.F / (*(a1 + (ii - jj) * lda)));
            for (k = ii - jj + 1; k < 4; k++) {
                *(b + k) = *(a1 + k * lda);
            }
        }
        if (ii - jj < 0) {
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a2 + 0);
            *(b + 2) = *(a3 + 0);
            *(b + 3) = *(a4 + 0);
        }
        a1++;
        a2++;
        a3++;
        a4++;
        b += 4;
        ii++;
    }
}
}
