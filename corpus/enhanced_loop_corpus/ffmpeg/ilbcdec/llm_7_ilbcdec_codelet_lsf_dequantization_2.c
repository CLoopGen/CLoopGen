#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t lsf_dim_codebook[];
extern  uint8_t lsf_size_codebook[];
extern  int16_t lsf_codebook[1088];
extern int16_t *lsfdeq;
extern int16_t *_usr_index;
extern int i;
extern int j;
extern int pos;
extern int cb_pos;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Eliminate loop-carried dependency on 'pos' and 'cb_pos' by computing absolute indices per iteration
    // and reverse inner loop to introduce different access pattern (still valid).
    for (i = 0; i < 3; i++) {
        int current_dim = lsf_dim_codebook[i];
        int current_size = lsf_size_codebook[i];
        int effective_cb_pos = 0;
        int effective_pos = 0;

        // Recompute effective positions without relying on previous state
        for (int k = 0; k < i; k++) {
            effective_pos += lsf_dim_codebook[k];
            effective_cb_pos += lsf_size_codebook[k] * lsf_dim_codebook[k];
        }

        // Reverse the inner loop to change access order (still writes same values)
        for (j = current_dim - 1; j >= 0; j--) {
            lsfdeq[10 + effective_pos + j] = lsf_codebook[effective_cb_pos + index[3 + i] * current_dim + j];
        }
        // Update outer state as in original
        pos += lsf_dim_codebook[i];
        cb_pos += current_size * current_dim;
    }
}
