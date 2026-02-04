#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG rows;
BLASLONG cols;
float *a;
BLASLONG lda;
BLASLONG i;
BLASLONG j;
float *aptr;

void init_vars() {
    rows = 4096;
    cols = 64;
    lda = 4096;

    a = (float *)calloc(rows * lda, sizeof(float));
    if (!a) {
        exit(1);
    }

    i = 0;
    j = 0;
    aptr = NULL;
}