#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int order;
int i;

void init_vars() {
    order = 64 * 1024 * 1024 / sizeof(int32_t); // ~256 MB total data (64M elements)
    size_t bytes = order * sizeof(int32_t);

    smp = (int32_t*)aligned_alloc(32, bytes);
    res = (int32_t*)aligned_alloc(32, bytes);

    if (!smp || !res) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < order; j++) {
        smp[j] = (int32_t)(j & 0xFF);
        res[j] = 0;
    }
}