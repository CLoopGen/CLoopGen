#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef float real_t;

__attribute__((aligned(64))) real_t flat_2d_array[65536];
__attribute__((aligned(64))) real_t a[32000];
real_t *restrict xx;

void init_vars() {
    for (int i = 0; i < 65536; i++) {
        flat_2d_array[i] = (real_t)(i % 100) / 10.0f;
    }
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)((i + 42) % 100) / 11.0f;
    }
    xx = aligned_alloc(64, 32000 * sizeof(real_t));
    for (int i = 0; i < 32000; i++) {
        xx[i] = 0.0f;
    }
}