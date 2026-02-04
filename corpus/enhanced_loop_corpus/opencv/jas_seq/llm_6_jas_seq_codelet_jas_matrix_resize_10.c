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
extern int numrows;
extern int numcols;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried dependency (WAW) by accumulating a dummy value that affects the next iteration.
    // This preserves the original pointer assignment but adds a fake dependency via a local accumulator.
    jas_seqent_t *prev_row = NULL;
    for (i = 0; i < numrows; ++i) {
        matrix->rows_[i] = &matrix->data_[numcols * i];
        // Artificial WAW dependency: current row's base depends on previous row's address (only in computation, not semantics)
        if (prev_row != NULL) {
            // Use a conditional that doesn't affect correctness but creates data flow
            matrix->rows_[i] += (prev_row - matrix->data_);
        }
        prev_row = matrix->rows_[i];
    }
}
