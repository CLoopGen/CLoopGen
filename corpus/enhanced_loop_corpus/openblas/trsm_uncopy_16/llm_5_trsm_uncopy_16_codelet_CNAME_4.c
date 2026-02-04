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
    if (diff >= 0 && diff < 1) {
        *(b + diff) = (1.F / (*(a1 + diff * lda)));
        k = diff + 1;
        if (k < 1) {
            *(b + k) = *(a1 + k * lda);
        }
    } else {
        *(b + 0) = *(a1 + 0);
    }
    a1++;
    b += 1;
    ii++;
}
}
