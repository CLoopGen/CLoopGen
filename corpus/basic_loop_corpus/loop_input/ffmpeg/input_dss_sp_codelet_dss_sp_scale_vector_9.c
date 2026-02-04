#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *vec;
int bits;
int size;
int i;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(int32_t);  // ~256 MB of data to ensure ~0.01s runtime
    vec = (int32_t*)aligned_alloc(32, size * sizeof(int32_t));
    if (!vec) {
        exit(1);
    }
    for (int j = 0; j < size; j++) {
        vec[j] = rand() % 1000;
    }
    bits = 2;  // reasonable shift value to avoid overflow and allow computation
    i = 0;
}