#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG rows;
BLASLONG cols;
float alpha;
float *a;
BLASLONG lda;
BLASLONG i;
BLASLONG j;
float *aptr;
float *bptr;
float tmp;

void init_vars() {
    rows = 2048;
    cols = 2048;
    alpha = 1.5f;
    lda = rows;

    a = (float*)calloc(rows * cols, sizeof(float));
    aptr = (float*)calloc(rows * cols, sizeof(float));

    for (BLASLONG idx = 0; idx < rows * cols; idx++) {
        a[idx] = (float)(idx % 100) / 10.0f;
        aptr[idx] = (float)((idx + 1) % 100) / 10.0f;
    }
}