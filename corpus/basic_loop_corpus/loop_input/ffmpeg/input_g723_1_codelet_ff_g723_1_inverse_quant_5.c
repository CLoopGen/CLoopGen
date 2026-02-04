#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t cur_lsp_array[10];
int16_t *cur_lsp = cur_lsp_array;
int min_dist = 256;
int i = 0;
int j = 0;
int temp = 0;
int stable = 0;

void init_vars() {
    for (int idx = 0; idx < 10; idx++) {
        cur_lsp[idx] = 1000 + idx * 3000;
    }
    min_dist = 256;
}