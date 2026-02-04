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

typedef jas_matrix_t jas_seq2d_t;

static jas_seq2d_t x_storage;
static jas_matrix_t y_storage;
static jas_seqent_t *x_data = NULL;
static jas_seqent_t **x_rows = NULL;
static jas_seqent_t *y_data = NULL;
static jas_seqent_t **y_rows = NULL;

jas_seq2d_t *x = &x_storage;
jas_matrix_t *y = &y_storage;
int i;
int j;

void init_vars() {
    const int target_mb = 64;
    const int element_size = sizeof(jas_seqent_t);
    const int total_elements = (target_mb * 1024 * 1024) / element_size;
    
    x_storage.numrows_ = 8000;
    x_storage.numcols_ = (total_elements + 7999) / 8000;
    y_storage.numrows_ = x_storage.numrows_;
    y_storage.numcols_ = x_storage.numcols_;
    
    size_t data_size = (size_t)x_storage.numrows_ * x_storage.numcols_;
    x_storage.datasize_ = data_size;
    y_storage.datasize_ = data_size;
    
    x_data = calloc(data_size, sizeof(jas_seqent_t));
    y_data = calloc(data_size, sizeof(jas_seqent_t));
    
    x_rows = malloc((size_t)x_storage.numrows_ * sizeof(jas_seqent_t*));
    y_rows = malloc((size_t)y_storage.numrows_ * sizeof(jas_seqent_t*));
    
    for (int r = 0; r < x_storage.numrows_; ++r) {
        x_rows[r] = &x_data[r * x_storage.numcols_];
        y_rows[r] = &y_data[r * y_storage.numcols_];
        
        for (int c = 0; c < x_storage.numcols_; ++c) {
            x_rows[r][c] = (jas_seqent_t)(r * x_storage.numcols_ + c);
        }
    }
    
    x_storage.rows_ = x_rows;
    y_storage.rows_ = y_rows;
}