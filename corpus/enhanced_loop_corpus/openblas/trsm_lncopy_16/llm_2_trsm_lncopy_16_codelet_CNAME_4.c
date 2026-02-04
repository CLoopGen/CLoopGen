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
    if ((ii >= jj) && (offset < 1)) {
        for (k = 0; k < offset; k++) {
            b[k] = a1[k * lda];
        }
        if (offset == 0) {
            b[0] = (1.F / a1[0]);
        }
    }
    if (offset >= 1) {
        b[0] = a1[0];
    }
    a1 += 1;
    b += 1;
    ii++;
}
}
