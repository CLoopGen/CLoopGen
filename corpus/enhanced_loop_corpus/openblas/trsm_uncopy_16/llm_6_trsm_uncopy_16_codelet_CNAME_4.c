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
    if ((offset >= 0) && (offset < 1)) {
        float inv = 1.F / (*(a1 + offset * lda));
        *(b + offset) = inv;
        for (k = offset + 1; k < 1; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    }
    if (offset < 0) {
        *(b + 0) = *(a1 + 0);
    }
    a1++;
    b += 1;
    ii++;
}
}
