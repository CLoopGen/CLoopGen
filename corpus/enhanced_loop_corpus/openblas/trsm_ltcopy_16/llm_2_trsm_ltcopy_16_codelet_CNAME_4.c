#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern float *a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG idx = ii - jj;
    if ((ii >= jj) && (idx < 1)) {
        b[idx] = 1.F / a1[idx];
    }
    if (idx < 0) {
        b[0] = a1[0];
    }
    b += 1;
    a1 += lda;
    ii++;
}
}
