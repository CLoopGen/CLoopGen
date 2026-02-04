#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lp_order = 20;

int16_t *lsp_2nd;
int16_t *lsp_prev;
int16_t lsp_1st[20];
int i;

void init_vars() {
    lsp_2nd = (int16_t*)aligned_alloc(16, sizeof(int16_t) * lp_order);
    lsp_prev = (int16_t*)aligned_alloc(16, sizeof(int16_t) * lp_order);

    for (i = 0; i < lp_order; i++) {
        lsp_2nd[i] = (int16_t)(i * 3);
        lsp_prev[i] = (int16_t)(i * 5);
        lsp_1st[i] = 0;
    }
}