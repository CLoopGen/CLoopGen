#include <stdlib.h>
#include <stdint.h>

float *m1;
float *m2;
float *result;
int i;

void init_vars() {
    size_t size = 64 * 1024 * 1024; // ~256 MB total for three arrays (64M elements * 4 bytes per float)
    m1 = (float*)aligned_alloc(32, size * sizeof(float));
    m2 = (float*)aligned_alloc(32, size * sizeof(float));
    result = (float*)aligned_alloc(32, size * sizeof(float));

    for (size_t idx = 0; idx < size; idx++) {
        m1[idx] = (float)(idx % 1000) + 1.0f;
        m2[idx] = (float)((idx % 1000) + 500) + 0.5f;
    }
}