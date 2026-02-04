#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lspf;
int i;

void init_vars() {
    const size_t data_size = 134217728; // ~128MB of float data to target ~0.01s runtime
    lspf = (float*)aligned_alloc(32, data_size * sizeof(float));
    if (!lspf) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        lspf[idx] = 1.0f + 0.01f * (idx % 100);
    }
}

__attribute__((destructor))
static void cleanup() {
    if (lspf) {
        free(lspf);
    }
}