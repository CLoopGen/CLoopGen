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
    float temp1 = 0.0F, temp2 = 0.0F, temp3 = 0.0F, temp4 = 0.0F;
    if ((ii >= jj) && (ii - jj < 4)) {
        temp1 = *(a1 + (ii - jj) * lda);
        *(b + ii - jj) = (1.F / temp1);
        for (k = ii - jj + 1; k < 4; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    }
    if (ii - jj < 0) {
        temp1 = *(a1 + 0);
        temp2 = *(a2 + 0);
        temp3 = *(a3 + 0);
        temp4 = *(a4 + 0);
        *(b + 0) = temp1;
        *(b + 1) = temp2;
        *(b + 2) = temp3;
        *(b + 3) = temp4;
    }
    a1++;
    a2++;
    a3++;
    a4++;
    b += 4;
    ii++;
}
}
