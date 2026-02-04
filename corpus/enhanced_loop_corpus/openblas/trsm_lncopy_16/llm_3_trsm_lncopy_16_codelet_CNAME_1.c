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
extern float *a5;
extern float *a6;
extern float *a7;
extern float *a8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = lda;
for (i = 0; i < m; i++) {
    BLASLONG diff = ii - jj;
    if ((ii >= jj) && (diff < 8)) {
        float* src_base = a1;
        for (k = 0; k <= diff; k++) {
            if (k < diff) {
                b[k] = src_base[k * stride];
            } else {
                b[k] = (1.F / src_base[k * stride]);
            }
        }
    }
    if (diff >= 8) {
        // Use strided read pattern: access every 'lda'-th element starting from current pointers
        b[0] = *(a1 + 0 * lda);
        b[1] = *(a2 + 0 * lda);
        b[2] = *(a3 + 0 * lda);
        b[3] = *(a4 + 0 * lda);
        b[4] = *(a5 + 0 * lda);
        b[5] = *(a6 + 0 * lda);
        b[6] = *(a7 + 0 * lda);
        b[7] = *(a8 + 0 * lda);
    }
    // Advance all input vectors by one in their base dimension
    a1 += 1;
    a2 += 1;
    a3 += 1;
    a4 += 1;
    a5 += 1;
    a6 += 1;
    a7 += 1;
    a8 += 1;
    b += 8;
    ii++;
}
}
