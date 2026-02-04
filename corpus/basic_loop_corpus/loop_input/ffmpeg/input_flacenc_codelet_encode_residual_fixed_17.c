#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int n;
int order;
int i;

void init_vars() {
    n = 64 * 1024 * 1024 / sizeof(int32_t); // ~256MB of total data
    order = 1024; // Start after a small offset

    res = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    smp = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    if (!res || !smp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < n; j++) {
        smp[j] = (int32_t)(j & 0xFFFFF);
    }
    for (int j = 0; j < order; j++) {
        res[j] = 0;
    }
}