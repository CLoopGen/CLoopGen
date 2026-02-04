#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *fixed_vector;
int i;
float cpe;
float last;

static float *internal_vector;

void init_vars() {
    size_t vector_size = 1 << 20; // Approximately 4MB of data (1M floats)
    internal_vector = (float *)calloc(vector_size, sizeof(float));
    if (!internal_vector) {
        exit(1);
    }

    fixed_vector = internal_vector;
    cpe = 0.5f;
    last = 1.0f;

    for (size_t idx = 0; idx < vector_size; ++idx) {
        fixed_vector[idx] = (float)(idx % 1000);
    }
}