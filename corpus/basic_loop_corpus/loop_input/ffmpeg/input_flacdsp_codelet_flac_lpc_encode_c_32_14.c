#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int order;
int i;

void init_vars() {
    order = 65536; // ~256MB total data (65536 * 4 bytes * 2 arrays)
    smp = (int32_t*)aligned_alloc(32, order * sizeof(int32_t));
    res = (int32_t*)aligned_alloc(32, order * sizeof(int32_t));

    for (int j = 0; j < order; j++) {
        smp[j] = (int32_t)(j & 0xFF);
    }
}