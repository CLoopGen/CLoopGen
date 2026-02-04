#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *lsp_2nd;
double *lsp_prev;
double lsp_1st[16];
int i;

void init_vars() {
    lsp_2nd = (double *)aligned_alloc(32, 16 * sizeof(double));
    lsp_prev = (double *)aligned_alloc(32, 16 * sizeof(double));

    for (int j = 0; j < 16; j++) {
        lsp_2nd[j] = (double)(j + 1) * 1.5;
        lsp_prev[j] = (double)(j + 1) * 2.5;
        lsp_1st[j] = 0.0;
    }
    i = 0;
}