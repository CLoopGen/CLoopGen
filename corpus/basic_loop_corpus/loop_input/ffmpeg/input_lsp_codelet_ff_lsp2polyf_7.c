#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *lsp;
double *f;
int lp_half_order;
int i;
int j;

void init_vars() {
    lp_half_order = 8192;

    lsp = (double *)aligned_alloc(32, (2 * lp_half_order + 1) * sizeof(double));
    f = (double *)aligned_alloc(32, (lp_half_order + 1) * sizeof(double));

    for (int idx = 0; idx <= 2 * lp_half_order; idx++) {
        lsp[idx] = (double)(idx % 128) * 0.01;
    }

    for (int idx = 0; idx <= lp_half_order; idx++) {
        f[idx] = (double)(idx % 256) * 0.005;
    }
}