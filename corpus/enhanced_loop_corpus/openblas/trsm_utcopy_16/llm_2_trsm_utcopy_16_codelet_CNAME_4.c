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
    if ((ii >= jj) && (ii - jj < 1)) {
        BLASLONG offset = ii - jj;
        for (k = 0; k < offset; k++) {
            b[k * 2] = a1[k * 2];  // Strided access with stride 2
        }
        b[offset * 2] = (1.F / a1[offset * 2]);  // Strided write
    }
    if (ii - jj >= 1) {
        b[0] = a1[0];
    }
    b += 1;
    a1 += lda;
    ii++;
}
}
