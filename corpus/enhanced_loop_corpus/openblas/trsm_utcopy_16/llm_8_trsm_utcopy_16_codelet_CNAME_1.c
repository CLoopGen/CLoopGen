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
    if ((ii >= jj) && (ii - jj < 16)) {
        for (k = 0; k < ii - jj; k += 2) {
            *(b + k) = *(a1 + k);
            if (k + 1 < ii - jj) {
                *(b + k + 1) = *(a1 + k + 1);
            }
        }
        *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
    }
    if (ii - jj >= 16) {
        for (k = 0; k < 16; k += 8) {
            *(b + k + 0) = *(a1 + k + 0);
            *(b + k + 1) = *(a1 + k + 1);
            *(b + k + 2) = *(a1 + k + 2);
            *(b + k + 3) = *(a1 + k + 3);
            *(b + k + 4) = *(a1 + k + 4);
            *(b + k + 5) = *(a1 + k + 5);
            *(b + k + 6) = *(a1 + k + 6);
            *(b + k + 7) = *(a1 + k + 7);
        }
    }
    b += 16;
    a1 += lda;
    ii++;
}
}
