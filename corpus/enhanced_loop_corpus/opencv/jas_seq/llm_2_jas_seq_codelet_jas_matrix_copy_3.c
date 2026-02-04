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

extern jas_matrix_t *x;
extern jas_matrix_t *y;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using flattened index with row-major order
    jas_seqent_t *y_data = y->data_;
    jas_seqent_t *x_data = x->data_;
    int_fast32_t numcols = x->numcols_;
    for (i = 0; i < x->numrows_; ++i) {
        int_fast32_t base_idx = i * numcols;
        for (j = 0; j < numcols; ++j) {
            y_data[base_idx + j] = x_data[base_idx + j];
        }
    }
}
