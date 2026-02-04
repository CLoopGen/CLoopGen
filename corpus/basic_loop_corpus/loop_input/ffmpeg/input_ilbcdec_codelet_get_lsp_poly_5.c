#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *lsp;
int32_t *f;
int16_t high;
int16_t low;
int i;
int j;
int k;
int l;
int32_t tmp;

void init_vars() {
    const size_t f_size = 256 * 1024 * sizeof(int32_t);
    const size_t lsp_size = 16 * sizeof(int16_t);

    f = aligned_alloc(32, f_size);
    lsp = aligned_alloc(32, lsp_size);

    for (size_t idx = 0; idx < f_size / sizeof(int32_t); idx++) {
        f[idx] = (int32_t)(idx * 789) ^ 0x12345678;
    }

    for (size_t idx = 0; idx < lsp_size / sizeof(int16_t); idx++) {
        lsp[idx] = (int16_t)(idx * 123) ^ 0x5A5A;
    }

    high = 0;
    low = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    tmp = 0;
}