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
    BLASLONG offset = prev_ii - jj;
    if ((prev_ii >= jj) && (offset < 16)) {
        for (k = 0; k <= offset; k++) {
            if (k < offset) {
                *(b + k) = *(a1 + k);
            } else {
                *(b + k) = (1.F / (*(a1 + k)));
            }
        }
    }
    if (offset >= 16) {
        for (k = 0; k < 16; k++) {
            *(b + k) = *(a1 + k);
        }
    }
    b += 16;
    a1 += lda;
    prev_ii++;
}
ii = prev_ii;
}
