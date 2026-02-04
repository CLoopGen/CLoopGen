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
BLASLONG offset_b, offset_a1;
for (i = 0; i < m; i++) {
    offset_b = 0;
    offset_a1 = 0;
    if ((ii >= jj) && (ii - jj < 8)) {
        for (k = 0; k < ii - jj; k++) {
            *(b + offset_b + k) = *(a1 + offset_a1 + k);
        }
        *(b + offset_b + (ii - jj)) = (1.F / (*(a1 + offset_a1 + (ii - jj))));
    }
    if (ii - jj >= 8) {
        for (k = 0; k < 8; k++) {
            *(b + offset_b + k) = *(a1 + offset_a1 + k);
        }
    }
    b += 8;
    a1 += lda;
    ii++;
}
}
