#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 2048;
float beta = 1.5f;
void *C;
int ldc = 2048;
int i;
int j;

void init_vars() {
    size_t total_size = (size_t)ldc * (size_t)N * sizeof(float) * 2;
    float *c_ptr = (float *)aligned_alloc(32, total_size);
    if (!c_ptr) {
        exit(1);
    }
    for (size_t idx = 0; idx < (total_size / sizeof(float)); idx++) {
        c_ptr[idx] = (float)(idx % 100) / 10.0f;
    }
    C = c_ptr;
}