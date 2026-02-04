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
    for (BLASLONG inner = 0; inner < 1; inner++) {
        if ((ii >= jj) && (ii - jj < 4)) {
            for (k = 0; k < ii - jj; k++) {
                *(b + k) = *(a1 + k);
            }
            *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
        }
        if (ii - jj >= 4) {
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a1 + 1);
            *(b + 2) = *(a1 + 2);
            *(b + 3) = *(a1 + 3);
        }
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
