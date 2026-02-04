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
BLASLONG prev_ii = ii;
for (i = 0; i < m; i++) {
    BLASLONG delta = prev_ii + i - jj;
    if ((prev_ii + i >= jj) && (delta < 1)) {
        for (k = 0; k < delta; k++) {
            b[k] = a1[k * lda];
        }
        if (delta == 0) {
            b[0] = (1.F / a1[0]);
        }
    }
    if (delta >= 1) {
        b[0] = a1[0];
    }
    a1++;
    b += 1;
}
}
