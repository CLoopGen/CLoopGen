#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *spec;
int transf_size;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)
    spec = (float*)aligned_alloc(32, data_size);
    if (!spec) {
        exit(1);
    }
    transf_size = data_size / sizeof(float);
    for (size_t idx = 0; idx < transf_size; ++idx) {
        spec[idx] = (float)(idx + 1);
    }
}