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
    if (diff == 0) {
        *(b + 0) = (1.F / (*(a1 + 0 * lda)));
        for (k = 1; k < 1; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    } else if (diff < 0) {
        *(b + 0) = *(a1 + 0);
    }
    a1++;
    b += 1;
    ii++;
}
}
