#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 200;
float *b;
BLASLONG i = 0;
BLASLONG ii = 1;
BLASLONG jj = 0;
BLASLONG k = 0;
float *a1;
float *orig_a1;

void init_vars() {
    orig_a1 = (float*)calloc(m * lda, sizeof(float));
    a1 = orig_a1;
    b = (float*)calloc(m, sizeof(float));
    for (BLASLONG j = 0; j < m * lda; j++) {
        orig_a1[j] = 1.0f + (j % 100);
    }
}