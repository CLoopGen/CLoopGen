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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    float temp[4];
    for (k = 0; k < 4; k++) {
        temp[k] = *(a1 + k);
    }
    if ((ii >= jj) && (ii - jj < 4)) {
        *(b + ii - jj) = (1.F / temp[ii - jj]);
        for (k = ii - jj + 1; k < 4; k++) {
            *(b + k) = temp[k];
        }
    }
    if (ii - jj < 0) {
        for (k = 0; k < 4; k++) {
            *(b + k) = temp[k];
        }
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
