#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

float *b_data;
float *a01_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for sufficient runtime

    b_data = (float*)aligned_alloc(64, data_size);
    a01_data = (float*)aligned_alloc(64, data_size);

    lda = 16;
    b = b_data;
    a01 = a01_data;

    for (size_t i = 0; i < data_size / sizeof(float); i++) {
        a01_data[i] = (float)(i % 1000) + 1.0f;
        b_data[i] = 0.0f;
    }
}