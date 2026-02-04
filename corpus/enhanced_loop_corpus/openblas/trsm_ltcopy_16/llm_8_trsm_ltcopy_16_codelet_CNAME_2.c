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
        float inv_diag = 1.F / (*(a1 + ii - jj));
        *(b + 0) = (ii - jj == 0) ? inv_diag : *(a1 + 0);
        *(b + 1) = (ii - jj == 1) ? inv_diag : *(a1 + 1);
        *(b + 2) = (ii - jj == 2) ? inv_diag : *(a1 + 2);
        *(b + 3) = (ii - jj == 3) ? inv_diag : *(a1 + 3);
    } else {
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
