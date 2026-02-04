#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *f;
int16_t *lsp;
int lp_half_order;
int i;
int j;

void init_vars() {
    lp_half_order = 4096;

    f = (int*)aligned_alloc(32, (lp_half_order + 1) * sizeof(int));
    lsp = (int16_t*)aligned_alloc(32, (2 * lp_half_order + 1) * sizeof(int16_t));

    for (i = 0; i <= lp_half_order; i++) {
        f[i] = i * 31;
    }
    for (i = 0; i <= 2 * lp_half_order; i++) {
        lsp[i] = (i * 17) % 32768 - 16384;
    }
}