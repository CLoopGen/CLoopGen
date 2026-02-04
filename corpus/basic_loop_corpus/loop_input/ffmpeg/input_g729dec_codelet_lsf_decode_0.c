#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t cb_lsp_1st[128][10] = {0};
int16_t cb_lsp_2nd[32][10] = {0};
int16_t vq_1st = 0;
int16_t vq_2nd_low = 0;
int16_t vq_2nd_high = 1;
int i = 0;
int16_t *quantizer_output;

void init_vars() {
    // Allocate quantizer_output with sufficient size to prevent out-of-bounds access
    quantizer_output = (int16_t*)calloc(10, sizeof(int16_t));

    // Initialize codebooks with non-zero values to allow meaningful computation
    for (int idx1 = 0; idx1 < 128; idx1++) {
        for (int idx2 = 0; idx2 < 10; idx2++) {
            cb_lsp_1st[idx1][idx2] = (int16_t)(idx1 + idx2);
        }
    }

    for (int idx1 = 0; idx1 < 32; idx1++) {
        for (int idx2 = 0; idx2 < 10; idx2++) {
            cb_lsp_2nd[idx1][idx2] = (int16_t)(idx1 - idx2);
        }
    }

    // Set indices within valid range
    vq_1st = 64;           // 0 <= vq_1st < 128
    vq_2nd_low = 16;       // 0 <= vq_2nd_low < 32
    vq_2nd_high = 17;      // 0 <= vq_2nd_high < 32

    // Ensure the loop accesses only valid indices: i from 0 to 4
    // Accesses: [i] and [i+5] => max index is 9, which is < 10 (valid)
}