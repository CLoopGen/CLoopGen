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
    // Variant 2: Strided memory access using pointer arithmetic with step
    for (i = 0; i < 3; i++) {
        int dim = lsf_dim_codebook[i];
        int stride = lsf_size_codebook[i];
        const int16_t* src = &lsf_codebook[cb_pos + index[i]];
        int16_t* dest = &lsfdeq[pos];
        for (j = 0; j < dim; j++) {
            dest[j] = src[j * stride]; // Strided read from codebook
        }
        pos += dim;
        cb_pos += stride * dim;
    }
}
