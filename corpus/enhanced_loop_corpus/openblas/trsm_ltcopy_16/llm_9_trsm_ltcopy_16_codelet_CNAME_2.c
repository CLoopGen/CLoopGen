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
BLASLONG stride = lda - 4;
for (i = 0; i < m; i += 2) {
    *(b + 0) = (ii - jj >= 0 && ii - jj < 4) ? (1.F / (*(a1 + ii - jj))) : *(a1 + 0);
    *(b + 1) = *(a1 + 1);
    *(b + 2) = *(a1 + 2);
    *(b + 3) = *(a1 + 3);

    b += 4;
    a1 += lda;
    ii++;

    if (i + 1 < m) {
        *(b + 0) = *(a1 + 0);
        *(b + 1) = *(a1 + 1);
        float temp = *(a1 + 2);
        *(b + 2) = temp * temp;
        *(b + 3) = *(a1 + 3);

        b += 4;
        a1 += lda;
        ii++;
    }
}
}
