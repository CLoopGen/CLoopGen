#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t lsf_dim_codebook[] = {34, 34, 34};
uint8_t lsf_size_codebook[] = {32, 32, 32};

int16_t lsf_codebook[1088];
int16_t *lsfdeq;
int16_t *_usr_index;

int i;
int j;
int pos;
int cb_pos;

#define index _usr_index

void init_vars() {
    // Allocate large enough data to make loop run ~0.01s
    // The inner loop runs total of sum(lsf_dim_codebook[0..2]) = 102 iterations per outer loop
    // To increase runtime, we scale up the data size but keep loop bounds as-is
    // The actual work is small, so we must make arrays large to avoid out-of-bounds

    // Total elements accessed in lsf_codebook: for each i, we access up to cb_pos + index[i]*dim + j
    // Max cb_pos after loops: sum_{i=0}^2 (size[i] * dim[i]) = 32*34 * 3 = 3264
    // Max index[i] should be less than lsf_size_codebook[i] -> max 31
    // So max offset into lsf_codebook: 3264 + 31*34 + 33 = 3264 + 1054 + 33 = ~4351
    // We allocate more than that to be safe

    // But note: lsf_codebook is fixed at 1088 -> too small! Need to adjust parameters to fit.

    // Adjust codebook sizes so that they fit in 1088 elements
    // Recompute valid dimensions:
    // We require: sum_{i=0}^2 (lsf_size_codebook[i] * lsf_dim_codebook[i]) <= 1088
    // Try smaller values:
    
    lsf_dim_codebook[0] = 16;
    lsf_dim_codebook[1] = 16;
    lsf_dim_codebook[2] = 16;
    lsf_size_codebook[0] = 8;
    lsf_size_codebook[1] = 8;
    lsf_size_codebook[2] = 8;

    // Now total required: for i: 8*16 = 128; total = 3*128 = 384 <= 1088 -> OK

    // Initialize lsf_codebook with dummy data
    for (int k = 0; k < 1088; k++) {
        lsf_codebook[k] = (int16_t)(k % 32768);
    }

    // Allocate lsfdeq: maximum pos reaches sum(dim) = 16*3 = 48
    lsfdeq = (int16_t*)calloc(64, sizeof(int16_t));

    // Allocate and initialize index array
    _usr_index = (int16_t*)malloc(3 * sizeof(int16_t));
    index[0] = 5;  // must be < lsf_size_codebook[0] = 8
    index[1] = 3;
    index[2] = 7;

    // Initialize state variables
    i = 0;
    j = 0;
    pos = 0;
    cb_pos = 0;
}