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

extern int numrows;
extern jas_matrix_t *matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = numrows / 2;
    int i;
    for (i = 0; i < outer; ++i) {
        matrix->rows_[i] = &matrix->data_[i * matrix->numcols_];
        matrix->rows_[i + outer] = &matrix->data_[(i + outer) * matrix->numcols_];
    }
    if (numrows % 2 == 1) {
        // Handle odd-sized numrows
        matrix->rows_[numrows - 1] = &matrix->data_[(numrows - 1) * matrix->numcols_];
    }
}
