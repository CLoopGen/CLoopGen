#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
real_t *restrict xx;

void init_vars() {
    for (int i = 0; i < 32000; i++) {
        a[i] = (real_t)(i % 100) / 10.0f;
        b[i] = 0.0f;
    }

    xx = (real_t* restrict)aligned_alloc(64, 32000 * sizeof(real_t));
    if (xx == NULL) {
        exit(1);
    }

    for (int i = 0; i < 32000; i++) {
        xx[i] = (real_t)((i + 10) % 100) / 12.0f;
    }
}