#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 2048;
BLASLONG cols = 2048;
float alpha = 1.5f;
BLASLONG lda = 2048;
BLASLONG i, j;
float *aptr;

static float adata[2048 * 2048];

void init_vars() {
    aptr = adata;
    for (BLASLONG idx = 0; idx < rows * cols; idx++) {
        adata[idx] = (float)(idx % 128);
    }
}