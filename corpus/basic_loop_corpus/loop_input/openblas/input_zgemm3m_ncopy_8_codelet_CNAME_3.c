#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG i;
float *a_offset1;
float *b_offset;
float a1;
float a2;

static float *a_data;
static float *b_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of input data (64M floats)
    m = data_size / 2;

    a_data = (float*)aligned_alloc(32, data_size * sizeof(float));
    b_data = (float*)aligned_alloc(32, (data_size / 2) * sizeof(float));

    if (!a_data || !b_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        a_data[idx] = 1.0f;
    }
    for (size_t idx = 0; idx < data_size / 2; idx++) {
        b_data[idx] = 0.0f;
    }

    a_offset1 = a_data;
    b_offset = b_data;
}