#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int n;
int order;
int i;
int a;
int c;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of input data for sufficient runtime
    n = data_size / sizeof(int32_t);
    order = 2;

    smp = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    res = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    for (int j = 0; j < n; ++j) {
        smp[j] = rand() % 1000;
    }

    a = 0;
    c = 0;
}