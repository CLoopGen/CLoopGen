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
    n = 32 * 1024 * 1024; // 32 million elements ~ 128 MB of data (each int32_t is 4 bytes)
    order = 1;

    smp = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    res = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    for (int j = 0; j < n; j++) {
        smp[j] = rand() % 1000;
        res[j] = 0;
    }
}