#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t dc_lsp[10] = {0};

int16_t cur_lsp_array[10];
int16_t prev_lsp_array[10];

int16_t *cur_lsp = cur_lsp_array;
int16_t *prev_lsp = prev_lsp_array;

int pred = 16384; 
int i = 0;
int temp = 0;

void init_vars() {
    for (int idx = 0; idx < 10; idx++) {
        dc_lsp[idx] = (int16_t)(idx * 32);
        cur_lsp_array[idx] = (int16_t)(idx * 100);
        prev_lsp_array[idx] = (int16_t)(idx * 200);
    }
    pred = 16384;
}