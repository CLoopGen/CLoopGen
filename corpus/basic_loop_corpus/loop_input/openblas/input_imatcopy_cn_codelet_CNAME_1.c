#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows;
BLASLONG cols;
BLASLONG lda;
BLASLONG i;
BLASLONG j;
float *aptr;

static float *data_ptr = NULL;

void init_vars() {
    rows = 2048;
    cols = 128;
    lda = rows;

    size_t data_size = (size_t)lda * (size_t)cols * sizeof(float);

    data_ptr = (float*)__builtin_malloc(data_size);
    aptr = data_ptr;

    for (size_t k = 0; k < data_size / sizeof(float); k++) {
        data_ptr[k] = 1.0f;
    }
}