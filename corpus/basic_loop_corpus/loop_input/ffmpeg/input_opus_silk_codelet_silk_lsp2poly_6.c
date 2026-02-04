#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t lsp[16];
int32_t pol[16];
int half_order;
int i;
int j;

void init_vars() {
    // Initialize half_order to 8 to ensure loop runs with valid bounds (i < half_order, and 2*i <= 15 for lsp indexing)
    half_order = 8;

    // Initialize lsp with non-zero values to make computation meaningful
    for (int idx = 0; idx < 16; idx++) {
        lsp[idx] = (int32_t)(idx * 37); // Arbitrary pattern
    }

    // Initialize pol array
    pol[0] = 1;
    pol[1] = 2;
    for (int idx = 2; idx < 16; idx++) {
        pol[idx] = (int32_t)(idx * 13);
    }

    // Initialize loop indices to safe values
    i = 0;
    j = 0;
}