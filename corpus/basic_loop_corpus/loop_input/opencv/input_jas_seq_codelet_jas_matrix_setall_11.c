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

jas_matrix_t *matrix;
jas_seqent_t val;
int i;
int j;
jas_seqent_t *rowstart;
int rowstep;
jas_seqent_t *data;

void init_vars() {
    val = 42;
    i = 0;
    j = 0;
    rowstart = 0;
    rowstep = 1;
    data = 0;

    matrix = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    matrix->numrows_ = 8192;
    matrix->numcols_ = 8192;
    matrix->maxrows_ = matrix->numrows_;
    matrix->datasize_ = matrix->numrows_ * matrix->numcols_;
    matrix->data_ = (jas_seqent_t*)calloc(matrix->datasize_, sizeof(jas_seqent_t));
    matrix->rows_ = (jas_seqent_t**)calloc(matrix->maxrows_, sizeof(jas_seqent_t*));

    for (int r = 0; r < matrix->numrows_; ++r) {
        matrix->rows_[r] = &matrix->data_[r * matrix->numcols_];
    }

    rowstart = 0;
    data = 0;
}