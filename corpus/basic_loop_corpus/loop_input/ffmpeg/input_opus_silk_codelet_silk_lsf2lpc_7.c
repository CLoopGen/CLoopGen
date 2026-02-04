#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

const uint8_t ff_silk_lsf_ordering_nbmb[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10 };
const uint8_t ff_silk_lsf_ordering_wb[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

static int16_t ff_silk_cosine_init[257];
const int16_t *ff_silk_cosine_ptr = ff_silk_cosine_init;
const int16_t ff_silk_cosine[257] = { 0 }; // Dummy definition to satisfy linkage; we will not modify it

int16_t nlsf[16];
int order;
int k;
int32_t lsp[16];

void init_vars() {
    order = 10;

    for (int i = 0; i < 16; i++) {
        nlsf[i] = rand() % 65536;
        lsp[i] = 0;
    }

    for (int i = 0; i < 257; i++) {
        int16_t val = (int16_t)(0x7FFF * (1.0 - 2.0 * i * i / (256.0 * 256.0)));
        ((int16_t*)ff_silk_cosine)[i] = val;
    }
}