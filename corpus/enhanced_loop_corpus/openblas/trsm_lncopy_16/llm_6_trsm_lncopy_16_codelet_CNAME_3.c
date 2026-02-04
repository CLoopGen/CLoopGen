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
    if ((ii >= jj) && (ii - jj < 2)) {
        float temp = 0.0F;
        for (k = 0; k < ii - jj; k++) {
            temp = *(a1 + k * lda);
            *(b + k) = temp;
        }
        temp = *(a1 + (ii - jj) * lda);
        *(b + ii - jj) = (1.F / temp);
    }
    if (ii - jj >= 2) {
        float val1 = *(a1 + 0);
        float val2 = *(a2 + 0);
        *(b + 0) = val1;
        *(b + 1) = val2;
    }
    a1++;
    a2++;
    b += 2;
    ii++;
}
}
