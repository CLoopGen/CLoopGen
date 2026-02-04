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
    // Variant 1: Consecutive memory access with precomputed base pointers
    for (i = 0; i < 3; i++) {
        int dim = lsf_dim_codebook[i];
        int base_idx = index[i] * dim;
        const int16_t* src_base = &lsf_codebook[cb_pos + base_idx];
        int16_t* dest_base = &lsfdeq[pos];
        for (j = 0; j < dim; j++) {
            dest_base[j] = src_base[j];
        }
        pos += dim;
        cb_pos += lsf_size_codebook[i] * dim;
    }
}
