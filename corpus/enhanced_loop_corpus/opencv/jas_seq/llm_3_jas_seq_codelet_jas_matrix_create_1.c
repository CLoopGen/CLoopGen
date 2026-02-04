#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jas_seqent_t;

typedef struct {
    int flags_;
    int_fast32_t xstart_;
    int_fast32_t ystart_;
    int_fast32_t xend_;
    int_fast32_t yend_;
    int_fast32_t numrows_;
    int_fast32_t numcols_;
    jas_seqent_t **rows_;
    int_fast32_t maxrows_;
    jas_seqent_t *data_;
    int_fast32_t datasize_;
} jas_matrix_t;

extern jas_matrix_t *matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with strided indexing as proxy for indirect pattern)
    int *indices = (int*)malloc(matrix->datasize_ * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int idx = 0; idx < matrix->datasize_; ++idx) {
        indices[idx] = idx; // Simulate precomputed or scrambled indices
    }
    int i;
    for (i = 0; i < matrix->datasize_; ++i) {
        matrix->data_[indices[i]] = 0;
    }
    free(indices);
}
