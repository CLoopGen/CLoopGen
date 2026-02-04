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
    if ((ii >= jj) && (offset < 16)) {
        float inv_diag = 1.F / (*(a1 + offset));
        *(b + 0) = inv_diag;
        for (k = 1; k < 16; k++) {
            *(b + k) = *(a1 + k);
        }
    } else if (offset < 0) {
        for (k = 0; k < 16; k++) {
            *(b + k) = *(a1 + k);
        }
    }
    b += 16;
    a1 += lda;
    ii++;
}
}
