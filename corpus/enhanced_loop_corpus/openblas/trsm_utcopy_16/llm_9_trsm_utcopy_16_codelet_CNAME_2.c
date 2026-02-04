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
for (i = 0; i < m; i += 2) {
    BLASLONG offset = ii - jj;
    if ((ii >= jj) && (offset < 4)) {
        for (k = 0; k < offset; k += 2) {
            if (k + 1 < offset) {
                *(b + k)     = *(a1 + k);
                *(b + k + 1) = *(a1 + k + 1);
            } else {
                *(b + k) = *(a1 + k);
            }
        }
        *(b + offset) = (1.F / (*(a1 + offset)));
        if (offset + 1 < 4) {
            *(b + offset + 1) = *(a1 + offset + 1);
        }
    }
    if (offset >= 4) {
        *(b + 0) = *(a1 + 0);
        *(b + 2) = *(a1 + 2);
    }
    b += 4;
    a1 += 2 * lda;
    ii += 2;
}
}
