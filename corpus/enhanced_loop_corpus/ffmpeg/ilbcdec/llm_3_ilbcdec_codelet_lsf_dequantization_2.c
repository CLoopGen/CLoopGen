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
    // Variant 2: Indirect memory access using pointer arithmetic and indirect indexing
    int8_t *deq_ptr = (int8_t*)&lsfdeq[10 + pos];
    for (i = 0; i < 3; i++) {
        int dim = lsf_dim_codebook[i];
        int size = lsf_size_codebook[i];
        int16_t *src_base = &lsf_codebook[cb_pos + index[3 + i] * dim];
        for (j = 0; j < dim; j++) {
            // Simulate irregular/indirect access pattern (though j is sequential, base is computed)
            *(int8_t*)((int16_t*)deq_ptr + j) = src_base[j];
        }
        deq_ptr += dim * sizeof(int16_t);
        cb_pos += size * dim;
        pos += dim;
    }
}
