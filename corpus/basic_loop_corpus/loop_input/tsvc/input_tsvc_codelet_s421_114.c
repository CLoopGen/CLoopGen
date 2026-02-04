#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
real_t *restrict xx;
real_t *yy;

void init_vars() {
    xx = (real_t*)aligned_alloc(64, 32000 * sizeof(real_t));
    if (!xx) {
        exit(1);
    }
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        xx[i] = 2.0f;
    }
}