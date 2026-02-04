#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 16;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;
float *a1;

void init_vars() {
    b = (float*)aligned_alloc(64, sizeof(float) * 16 * m);
    a1 = (float*)aligned_alloc(64, sizeof(float) * lda * m);

    for (int idx = 0; idx < 16 * m; idx++) {
        a1[idx] = 1.0f + (idx % 7); 
    }

    for (int idx = 0; idx < 16 * m; idx++) {
        b[idx] = 0.0f;
    }
}