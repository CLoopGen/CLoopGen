#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG i;
float *a_offset1;
float *b_offset;
float a1;
float a2;

static float *a_data;
static float *b_data;
static BLASLONG data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~256 MB of input data (64M pairs of float)
    m = data_size / 2;

    a_data = (float*)aligned_alloc(32, data_size * sizeof(float));
    b_data = (float*)aligned_alloc(32, (data_size / 2) * sizeof(float));

    if (!a_data || !b_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (BLASLONG j = 0; j < data_size; j++) {
        a_data[j] = (float)(j % 127 + 1);
    }
    for (BLASLONG j = 0; j < data_size / 2; j++) {
        b_data[j] = 0.0f;
    }

    a_offset1 = a_data;
    b_offset = b_data;
}