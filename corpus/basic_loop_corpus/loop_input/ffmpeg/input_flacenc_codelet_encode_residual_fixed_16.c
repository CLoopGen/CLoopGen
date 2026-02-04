#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int order;
int i;

void init_vars() {
    order = 64 * 1024 * 1024 / sizeof(int32_t); // ~256MB total data size
    size_t bytes = order * sizeof(int32_t);

    smp = (int32_t*)aligned_alloc(32, bytes);
    res = (int32_t*)aligned_alloc(32, bytes);

    if (!smp || !res) {
        exit(1);
    }

    for (int j = 0; j < order; j++) {
        smp[j] = (int32_t)(j & 0xFF);
    }

    i = 0;
}