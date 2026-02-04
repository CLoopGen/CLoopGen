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
jas_seqent_t minval = -1000;
jas_seqent_t maxval = 1000;
int i;
int j;
jas_seqent_t v;
jas_seqent_t *rowstart;
jas_seqent_t *data;
int rowstep;

static jas_seqent_t *allocated_data;
static jas_seqent_t **allocated_rows;

void init_vars() {
    const int target_size_mb = 64;
    const int element_size = sizeof(jas_seqent_t);
    const int total_elements = (target_size_mb * 1024 * 1024) / element_size;
    
    matrix = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    if (!matrix) exit(1);

    matrix->numrows_ = 8192;
    matrix->numcols_ = (total_elements + matrix->numrows_ - 1) / matrix->numrows_;
    matrix->maxrows_ = matrix->numrows_;
    matrix->datasize_ = matrix->numrows_ * matrix->numcols_;

    allocated_data = (jas_seqent_t*)calloc(matrix->datasize_, sizeof(jas_seqent_t));
    if (!allocated_data) exit(1);

    allocated_rows = (jas_seqent_t**)calloc(matrix->numrows_, sizeof(jas_seqent_t*));
    if (!allocated_rows) exit(1);

    for (int r = 0; r < matrix->numrows_; ++r) {
        allocated_rows[r] = &allocated_data[r * matrix->numcols_];
        for (int c = 0; c < matrix->numcols_; ++c) {
            allocated_rows[r][c] = (r + c) % 2000 - 1000;
        }
    }

    matrix->data_ = allocated_data;
    matrix->rows_ = allocated_rows;
    matrix->xstart_ = 0;
    matrix->ystart_ = 0;
    matrix->xend_ = matrix->numcols_ - 1;
    matrix->yend_ = matrix->numrows_ - 1;
    matrix->flags_ = 0;

    rowstep = 1;
    rowstart = matrix->rows_[0];
    data = 0;
    v = 0;
}