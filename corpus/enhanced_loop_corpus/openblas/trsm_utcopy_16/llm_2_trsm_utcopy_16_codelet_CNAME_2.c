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
    BLASLONG offset = ii - jj;
    if ((ii >= jj) && (offset < 4)) {
        for (k = 0; k <= offset; k++) {
            b[k] = a1[k];
        }
        b[offset] = (1.F / a1[offset]);
    }
    if (offset >= 4) {
        b[0] = a1[0];
        b[1] = a1[1];
        b[2] = a1[2];
        b[3] = a1[3];
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
