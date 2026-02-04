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
    if ((ii >= jj) && (ii - jj < 4)) {
        *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
        for (k = ii - jj + 1; k < 4; k++) {
            *(b + k) = *(a1 + k);
        }
    } else if (ii - jj < 0) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
        *(b + 2) = *(a1 + 2);
        *(b + 3) = *(a1 + 3);
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
