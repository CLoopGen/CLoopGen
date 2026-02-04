#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t bandwidth_expand[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int16_t lpc_storage[10] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
int16_t *lpc = lpc_storage;

int16_t lsp_storage[10];
int16_t *lsp = lsp_storage;

int i;

void init_vars() {
    for (int j = 0; j < 10; j++) {
        lsp[j] = 0;
    }
}