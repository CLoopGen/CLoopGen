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
    int_fast32_t numcols_;
    int_fast32_t numrows_;
    jas_seqent_t **rows_;
    int_fast32_t maxrows_;
    jas_seqent_t *data_;
    int_fast32_t datasize_;
} jas_matrix_t;

int numrows;
jas_matrix_t *matrix;
int i;

void init_vars() {
    const size_t target_data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec on modern CPU
    const int_fast32_t estimated_numcols = 8192;
    numrows = target_data_size / (sizeof(jas_seqent_t) * estimated_numcols);
    if (numrows == 0) numrows = 1;
    
    matrix = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    matrix->numrows_ = numrows;
    matrix->numcols_ = estimated_numcols;
    matrix->datasize_ = numrows * matrix->numcols_;
    matrix->maxrows_ = numrows;

    matrix->data_ = (jas_seqent_t*)calloc(matrix->datasize_, sizeof(jas_seqent_t));
    matrix->rows_ = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));

    for (int i = 0; i < numrows; ++i) {
        matrix->rows_[i] = &matrix->data_[i * matrix->numcols_];
    }
}