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
    for (BLASLONG inner = 0; inner < 1; inner++) {
        if ((ii >= jj) && (ii - jj < 4)) {
            for (k = 0; k < ii - jj; k++) {
                *(b + k) = *(a1 + k * lda);
            }
            *(b + ii - jj) = (1.F / (*(a1 + (ii - jj) * lda)));
        }
        if (ii - jj >= 4) {
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a2 + 0);
            *(b + 2) = *(a3 + 0);
            *(b + 3) = *(a4 + 0);
        }
    }
    a1++;
    a2++;
    a3++;
    a4++;
    b += 4;
    ii++;
}
}
