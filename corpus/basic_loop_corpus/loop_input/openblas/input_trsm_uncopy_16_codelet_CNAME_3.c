#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
BLASLONG jj;
BLASLONG k;
float *a1;
float *a2;

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

static float *alloc_and_init_float_array(size_t n) {
    float *arr = (float*)calloc(n, sizeof(float));
    for (size_t idx = 0; idx < n; idx++) {
        arr[idx] = 1.0f + (float)(idx % 100);
    }
    return arr;
}

void init_vars() {
    m = DATA_SIZE_MB * 262144; 

    lda = 2;

    a1 = alloc_and_init_float_array(TOTAL_FLOATS);
    a2 = alloc_and_init_float_array(TOTAL_FLOATS);
    b = (float*)calloc(TOTAL_FLOATS, sizeof(float));

    ii = 0;
    jj = 0;

    for (i = 0; i < TOTAL_FLOATS; i++) {
        if (i % 2 == 0) {
            *(a1 + i) = 2.0f;
        } else {
            *(a1 + i) = 1.0f;
        }
    }
}