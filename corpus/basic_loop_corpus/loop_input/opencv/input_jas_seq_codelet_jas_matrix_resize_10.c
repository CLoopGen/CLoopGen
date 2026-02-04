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
int numrows;
int numcols;
int i;

void init_vars() {
    numrows = 8192;
    numcols = 8192;

    matrix = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    matrix->numrows_ = numrows;
    matrix->numcols_ = numcols;
    matrix->maxrows_ = numrows;
    matrix->datasize_ = numrows * numcols;

    matrix->data_ = (jas_seqent_t*)calloc(matrix->datasize_, sizeof(jas_seqent_t));
    matrix->rows_ = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));

    if (!matrix->data_ || !matrix->rows_) {
        exit(1);
    }
}