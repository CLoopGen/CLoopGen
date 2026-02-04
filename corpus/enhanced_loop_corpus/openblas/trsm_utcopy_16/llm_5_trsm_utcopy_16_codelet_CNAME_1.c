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
    BLASLONG diff = ii - jj;
    if (ii >= jj) {
        if (diff < 8) {
            for (k = 0; k <= diff; k++) {
                if (k < diff) {
                    *(b + k) = *(a1 + k);
                } else {
                    *(b + k) = (1.F / (*(a1 + k)));
                }
            }
        } else {
            for (k = 0; k < 8; k++) {
                *(b + k) = *(a1 + k);
            }
        }
    }
    b += 8;
    a1 += lda;
    ii++;
}
}
