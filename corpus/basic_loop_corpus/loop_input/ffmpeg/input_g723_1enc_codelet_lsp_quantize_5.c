#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int16_t *lsp;
int16_t weight[10];
int16_t min;
int i;

void init_vars() {
    lsp = (int16_t*)aligned_alloc(32, 10 * sizeof(int16_t));
    if (!lsp) {
        exit(1);
    }

    for (int idx = 0; idx < 10; idx++) {
        lsp[idx] = rand() % 1000;
    }

    for (int idx = 0; idx < 10; idx++) {
        weight[idx] = 0;
    }

    min = 0;
    i = 0;
}