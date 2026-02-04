#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int n = 65536;          // ~256KB input, ensures loop runs long enough (~0.01 sec on modern CPU)
int order = 1;
int i;
int a = 0;
int c = 0;
int e = 0;

void init_vars() {
    smp = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    res = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    for (int j = 0; j < n; ++j) {
        smp[j] = rand() % 1000;
        res[j] = 0;
    }

    a = 0;
    c = 0;
    e = 0;
}