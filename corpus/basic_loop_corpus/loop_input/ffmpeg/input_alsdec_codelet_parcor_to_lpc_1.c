#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int k = 1024;

int32_t *par;
int32_t *cof;

int i;
int j;

void init_vars() {
    par = (int32_t*)aligned_alloc(32, (k + 1) * sizeof(int32_t));
    cof = (int32_t*)aligned_alloc(32, k * sizeof(int32_t));

    for (unsigned int idx = 0; idx <= k; idx++) {
        par[idx] = rand() % 1000 - 500;
    }
    for (unsigned int idx = 0; idx < k; idx++) {
        cof[idx] = rand() % 1000 - 500;
    }
}