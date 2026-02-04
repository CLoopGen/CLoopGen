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
int n;
int i;
int j;
jas_seqent_t *rowstart;
int rowstep;
jas_seqent_t *data;

static jas_seqent_t* allocated_data = 0;
static jas_seqent_t** allocated_rows = 0;

void init_vars() {
    const int target_time_us = 10000; // ~0.01 seconds
    const long long mem_size = (long long)1 << 24; // 16 MB of data (adjustable)

    matrix = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    if (!matrix) exit(1);

    matrix->numrows_ = 4096;
    matrix->numcols_ = 4096;
    matrix->maxrows_ = matrix->numrows_;
    matrix->datasize_ = matrix->numrows_ * matrix->numcols_;

    allocated_data = (jas_seqent_t*)calloc(matrix->datasize_, sizeof(jas_seqent_t));
    if (!allocated_data) exit(1);

    allocated_rows = (jas_seqent_t**)calloc(matrix->numrows_, sizeof(jas_seqent_t*));
    if (!allocated_rows) exit(1);

    for (int r = 0; r < matrix->numrows_; ++r) {
        allocated_rows[r] = allocated_data + r * matrix->numcols_;
    }

    matrix->rows_ = allocated_rows;
    matrix->data_ = allocated_data;

    for (int k = 0; k < matrix->datasize_; ++k) {
        allocated_data[k] = (jas_seqent_t)(k & 0xFFFFF);
    }

    n = 2;
    rowstep = matrix->numcols_;
    rowstart = 0;
    data = 0;
}