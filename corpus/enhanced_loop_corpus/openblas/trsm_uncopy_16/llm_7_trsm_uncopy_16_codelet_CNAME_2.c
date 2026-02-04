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
extern float *a2;
extern float *a3;
extern float *a4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG local_offset;
for (i = 0; i < m; i++) {
    local_offset = ii - jj;
    if ((ii >= jj) && (local_offset < 4)) {
        *(b + local_offset) = (1.F / (*(a1 + local_offset * lda)));
        for (k = local_offset + 1; k < 4; k++) {
            *(b + k) = *(a1 + k * lda);
        }
    }
    if (local_offset < 0) {
        *(b + 0) = *(a1 + 0 * lda);
        *(b + 1) = *(a2 + 0 * lda);
        *(b + 2) = *(a3 + 0 * lda);
        *(b + 3) = *(a4 + 0 * lda);
    }
    a1 += 1;
    a2 += 1;
    a3 += 1;
    a4 += 1;
    b += 4;
    ii += 1;
}
}
