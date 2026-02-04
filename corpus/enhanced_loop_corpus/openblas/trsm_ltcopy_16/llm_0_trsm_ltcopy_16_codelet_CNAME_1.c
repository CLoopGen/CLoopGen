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
    for (BLASLONG inner = 0; inner < 1; inner++) {
        if ((ii >= jj) && (ii - jj < 8)) {
            *(b + ii - jj) = (1.F / (*(a1 + ii - jj)));
            for (k = ii - jj + 1; k < 8; k++) {
                *(b + k) = *(a1 + k);
            }
        }
        if (ii - jj < 0) {
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a1 + 1);
            *(b + 2) = *(a1 + 2);
            *(b + 3) = *(a1 + 3);
            *(b + 4) = *(a1 + 4);
            *(b + 5) = *(a1 + 5);
            *(b + 6) = *(a1 + 6);
            *(b + 7) = *(a1 + 7);
        }
    }
    b += 8;
    a1 += lda;
    ii++;
}
}
