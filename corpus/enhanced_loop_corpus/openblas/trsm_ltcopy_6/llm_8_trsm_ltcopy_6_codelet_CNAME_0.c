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
    if ((ii >= jj) && (ii - jj < 4)) {
        float inv = 1.F / (*(a1 + ii - jj));
        *(b + 0) = (ii - jj == 0) ? inv : *(a1 + 0);
        *(b + 1) = (ii - jj == 1) ? inv : *(a1 + 1);
        *(b + 2) = (ii - jj == 2) ? inv : *(a1 + 2);
        *(b + 3) = (ii - jj == 3) ? inv : *(a1 + 3);
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
