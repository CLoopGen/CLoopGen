#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

// External variable definitions
uint8_t lsf_dim_codebook[3] = { 34, 34, 34 }; // Dimensions for each codebook segment
uint8_t lsf_size_codebook[3] = { 32, 32, 32 }; // Sizes for each codebook

int16_t lsf_codebook[1088];

int16_t *lsfdeq;
int16_t *_usr_index;

int i;
int j;
int pos;
int cb_pos;

#define index _usr_index

void init_vars() {
    // Allocate lsfdeq with sufficient size to prevent out-of-bounds access
    // The loop accesses lsfdeq[10 + pos + j], where pos accumulates lsf_dim_codebook[i]
    // Total offset: 10 + (34+34+34) + 34 = 10 + 102 + 34 = 146 max -> allocate extra margin
    lsfdeq = (int16_t *)calloc(256, sizeof(int16_t));
    
    // Allocate and initialize _usr_index
    // Index is accessed as index[3 + i], i from 0 to 2 -> need at least 6 elements
    _usr_index = (int16_t *)calloc(6, sizeof(int16_t));
    _usr_index[3] = 0;   // index for first codebook
    _usr_index[4] = 1;   // index for second
    _usr_index[5] = 2;   // index for third

    // Initialize lsf_codebook with dummy data
    // Total required: cb_pos + index[3+i]*dim + j -> max index: 
    // cb_pos starts at 0, then increases by size*dim each iteration
    // Max access: during third iteration: cb_pos_prev + index[5]*34 + 33
    // cb_pos after two iterations: (32*34)*2 = 2176
    // Then access: 2176 + 2*34 + 33 = 2176 + 68 + 33 = 2277 -> but lsf_codebook only has 1088
    // So we must ensure that index values are scaled down to fit within 1088

    // Adjust indexing logic: we cannot exceed 1088
    // Let's reduce the effective multiplier so that:
    // max index used: index[3+i] < (1088 / (max dim)) => 1088 / 34 = 32
    // So valid indices are 0..31 -> our index[3+i] values (0,1,2) are safe

    // But cb_pos accumulates: size * dim = 32*34 = 1088 per block -> exceeds array!
    // Therefore, we must reinterpret: likely lsf_codebook holds all codebooks consecutively
    // And cb_pos should index into it. But total size needed: 3 * 32 * 34 = 3264 -> too big

    // Instead, fix: make lsf_codebook large enough
    // We change lsf_codebook to hold 3 * 32 * 34 = 3264 entries
    // But original declaration says [1088] -> conflict

    // Re-evaluate: perhaps lsf_size_codebook[i] is number of vectors, dim is dimension
    // So total entries per i: size * dim = 32*34=1088 -> so entire lsf_codebook is just one segment?
    // But loop uses index[3+i] which selects a vector within codebook i

    // Correct interpretation: lsf_codebook is partitioned into 3 parts
    // Part i starts at offset S_i and contains lsf_size_codebook[i] * lsf_dim_codebook[i] elements
    // We set cumulative offsets

    // Redefine lsf_codebook to be large enough: sum over i of (size * dim)
    // But original says [1088] -> so assume total size is 1088
    // Then: 3 * 32 * 34 = 3264 > 1088 -> impossible

    // Therefore, adjust parameters to fit 1088
    // Try smaller dimensions: let’s set dim = 16, size = 22 -> 22*16=352 per block, 3 blocks: 1056
    // Change lsf_dim_codebook and lsf_size_codebook accordingly

    // Reset everything with safe sizes fitting 1088 total
    free(lsfdeq);
    free(_usr_index);

    // New plan: use smaller dimensions
    for (int k = 0; k < 3; k++) {
        lsf_dim_codebook[k] = 16;      // 16 dimensions per vector
        lsf_size_codebook[k] = 22;     // 22 vectors per codebook
    }

    // Total lsf_codebook size: must be at least sum of (size * dim) for all i? Or shared?
    // Likely shared storage: total needed: 22*16 * 3 = 1056 < 1088 -> fits

    // Initialize lsf_codebook
    for (int k = 0; k < 1088; k++) {
        lsf_codebook[k] = (int16_t)(k & 0xFFFF);
    }

    // Allocate lsfdeq: max access: 10 + pos + j
    // pos accumulates: 16 + 16 + 16 = 48
    // j up to 15 -> max index: 10 + 48 + 15 = 73
    lsfdeq = (int16_t *)calloc(128, sizeof(int16_t));

    // Allocate and initialize _usr_index: need 6 elements (index[3+i] for i=0,1,2)
    _usr_index = (int16_t *)calloc(6, sizeof(int16_t));
    _usr_index[3] = 0;   // selects first vector in first codebook
    _usr_index[4] = 1;   // second
    _usr_index[5] = 2;   // third

    // Initialize state variables
    i = 0;
    j = 0;
    pos = 0;
    cb_pos = 0;

    // Ensure no overflow in lsf_codebook indexing:
    // For i=0: index = cb_pos + index[3+0]*dim + j = 0 + 0*16 + j = j -> 0..15
    // For i=1: cb_pos += 22*16 = 352; index = 352 + 1*16 + j = 368 + j -> 368..383
    // For i=2: cb_pos += 352 = 704; total = 352+352=704; index = 704 + 2*16 + j = 736 + j -> 736..751
    // All < 1088 -> safe
}