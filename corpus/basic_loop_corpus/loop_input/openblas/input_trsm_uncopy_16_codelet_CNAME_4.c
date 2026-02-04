#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 200;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;
float *a1;

void init_vars() {
    a1 = (float *)aligned_alloc(32, m * sizeof(float));
    b = (float *)aligned_alloc(32, m * sizeof(float));

    if (!a1 || !b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (BLASLONG idx = 0; idx < m; idx++) {
        a1[idx] = 1.0f + (idx % 5);
        b[idx] = 0.0f;
    }
}