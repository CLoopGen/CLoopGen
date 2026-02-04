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
int i;

void init_vars() {
    matrix = (jas_matrix_t *)malloc(sizeof(jas_matrix_t));
    if (!matrix) exit(1);

    matrix->datasize_ = 64 * 1024 * 1024 / sizeof(jas_seqent_t); // ~256MB total data
    matrix->data_ = (jas_seqent_t *)calloc(matrix->datasize_, sizeof(jas_seqent_t));
    if (!matrix->data_) exit(1);

    matrix->maxrows_ = 1;
    matrix->numrows_ = 1;
    matrix->numcols_ = matrix->datasize_;
    matrix->xstart_ = 0;
    matrix->ystart_ = 0;
    matrix->xend_ = matrix->numcols_;
    matrix->yend_ = matrix->numrows_;
    matrix->rows_ = (jas_seqent_t **)malloc(matrix->maxrows_ * sizeof(jas_seqent_t *));
    if (!matrix->rows_) exit(1);
    matrix->rows_[0] = matrix->data_;

    matrix->flags_ = 0;
}