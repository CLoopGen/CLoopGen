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

jas_matrix_t *mat0;
jas_matrix_t *mat1;
int r0;
int c0;
int i;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // ~64 MB of data for sufficient workload

    mat1 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    mat0 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));

    mat1->numrows_ = 8000;
    mat1->numcols_ = total_data_size / (mat1->numrows_ * sizeof(jas_seqent_t));
    mat1->datasize_ = mat1->numrows_ * mat1->numcols_;
    mat1->data_ = (jas_seqent_t*)calloc(mat1->datasize_, sizeof(jas_seqent_t));
    mat1->rows_ = (jas_seqent_t**)calloc(mat1->numrows_, sizeof(jas_seqent_t*));
    for (int row = 0; row < mat1->numrows_; ++row) {
        mat1->rows_[row] = &mat1->data_[row * mat1->numcols_];
    }

    r0 = 100;
    c0 = 50;

    mat0->numrows_ = 7500; // Ensure r0 + i < mat1->numrows_
    mat0->numcols_ = mat1->numcols_ - c0; // Ensure c0 + col access stays in bounds
    mat0->maxrows_ = mat0->numrows_;
    mat0->rows_ = (jas_seqent_t**)calloc(mat0->numrows_, sizeof(jas_seqent_t*));
}