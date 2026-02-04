#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern float *a1;
extern BLASLONG k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG offset = 0;
for (i = 0; i < m; i++) {
    offset = ii - jj;
    if ((ii >= jj) && (offset < 4)) {
        for (k = 0; k <= offset; k++) {
            if (k < offset) {
                *(b + k) = *(a1 + k);
            } else {
                *(b + k) = (1.F / (*(a1 + k)));
            }
        }
    }
    if (offset >= 4) {
        for (k = 0; k < 4; k++) {
            *(b + k) = *(a1 + k);
        }
    }
    b += 4;
    a1 += lda;
    ii++;
}
}
