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
extern int n;
extern int i;
extern int j;
extern jas_seqent_t *rowstart;
extern int rowstep;
extern jas_seqent_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Flattened single loop by merging row and column iterations
    // The original 2D iteration is converted into a 1D linear traversal using index arithmetic.
    jas_seqent_t *data_ptr = matrix->data_;
    int total_elements = matrix->numrows_ * matrix->numcols_;
    for (i = 0; i < total_elements; ++i) {
        jas_seqent_t val = data_ptr[i];
        data_ptr[i] = (val >= 0) ? (val >> n) : (-((-val) >> n));
    }
}
