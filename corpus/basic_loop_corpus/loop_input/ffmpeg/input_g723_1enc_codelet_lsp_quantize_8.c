#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dc_lsp[10];
int16_t lsp_storage[10];
int16_t prev_lsp_storage[10];
int16_t *lsp = lsp_storage;
int16_t *prev_lsp = prev_lsp_storage;
int i;

void init_vars() {
    for (i = 0; i < 10; i++) {
        dc_lsp[i] = (int16_t)(i * 37 % 1000);
        lsp_storage[i] = (int16_t)(i * 101 % 2000);
        prev_lsp_storage[i] = (int16_t)(i * 137 % 3000);
    }
    i = 0;
}