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

jas_matrix_t *x;
jas_matrix_t *y;
int i;
int j;

void init_vars() {
    const int target_size_mb = 64;
    const int element_size = sizeof(jas_seqent_t);
    const int total_elements = (target_size_mb * 1024 * 1024) / element_size;
    
    int rows = 8000;
    int cols = total_elements / rows;
    if (cols == 0) cols = 1;
    int actual_elements = rows * cols;
    
    x = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    y = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    
    x->numrows_ = rows;
    x->numcols_ = cols;
    x->rows_ = (jas_seqent_t**)calloc(rows, sizeof(jas_seqent_t*));
    x->data_ = (jas_seqent_t*)calloc(actual_elements, sizeof(jas_seqent_t));
    x->datasize_ = actual_elements;
    
    for (int r = 0; r < rows; ++r) {
        x->rows_[r] = &x->data_[r * cols];
    }
    
    y->numrows_ = rows;
    y->numcols_ = cols;
    y->rows_ = (jas_seqent_t**)calloc(rows, sizeof(jas_seqent_t*));
    y->data_ = (jas_seqent_t*)calloc(actual_elements, sizeof(jas_seqent_t));
    y->datasize_ = actual_elements;
    
    for (int r = 0; r < rows; ++r) {
        y->rows_[r] = &y->data_[r * cols];
    }
}