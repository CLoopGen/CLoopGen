#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern float *a1;
extern BLASLONG k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    float temp[4];
    if ((ii >= jj) && (ii - jj < 4)) {
        temp[ii - jj] = (1.F / (*(a1 + ii - jj)));
        for (k = ii - jj + 1; k < 4; k++) {
            temp[k] = *(a1 + k);
        }
        for (k = (ii - jj); k < 4; k++) {
            *(b + k - (ii - jj)) = temp[k];
        }
    }
    if (ii - jj < 0) {
        temp[0] = *(a1 + 0);
        temp[1] = *(a1 + 1);
        temp[2] = *(a1 + 2);
        temp[3] = *(a1 + 3);
        for (k = 0; k < 4; k++) {
            *(b + k) = temp[k];
        }
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
