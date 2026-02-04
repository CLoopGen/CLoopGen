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

typedef jas_matrix_t jas_seq_t;

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jas_seq_t *x;
jas_seq_t *y;
int i;
int j;
int k;
jas_seq_t *z;
jpc_fix_t s;
jpc_fix_t v;

static jas_seqent_t* alloc_data(int_fast32_t size) {
    return calloc(size, sizeof(jas_seqent_t));
}

static jas_seqent_t** alloc_rows(int_fast32_t rows, int_fast32_t cols) {
    jas_seqent_t** row_ptr = malloc(rows * sizeof(jas_seqent_t*));
    for (int i = 0; i < rows; ++i) {
        row_ptr[i] = alloc_data(cols);
    }
    return row_ptr;
}

void init_vars() {
    const int data_size_x = 1 << 18;  // ~256KB of data
    const int data_size_y = 1 << 14;
    const int data_size_z = 1 << 18;

    x = malloc(sizeof(jas_matrix_t));
    y = malloc(sizeof(jas_matrix_t));
    z = malloc(sizeof(jas_matrix_t));

    x->xstart_ = 0;
    x->xend_ = data_size_x;
    x->numcols_ = data_size_x;
    x->datasize_ = data_size_x;
    x->data_ = alloc_data(data_size_x);
    x->rows_ = alloc_rows(1, data_size_x);
    x->maxrows_ = 1;
    x->numrows_ = 1;

    y->xstart_ = 0;
    y->xend_ = data_size_y;
    y->numcols_ = data_size_y;
    y->datasize_ = data_size_y;
    y->data_ = alloc_data(data_size_y);
    y->rows_ = alloc_rows(1, data_size_y);
    y->maxrows_ = 1;
    y->numrows_ = 1;

    z->xstart_ = 0;
    z->xend_ = data_size_z;
    z->numcols_ = data_size_z;
    z->datasize_ = data_size_z;
    z->data_ = alloc_data(data_size_z);
    z->rows_ = alloc_rows(1, data_size_z);
    z->maxrows_ = 1;
    z->numrows_ = 1;

    for (int idx = 0; idx < data_size_x; ++idx) {
        x->rows_[0][idx] = rand() % 1000 - 500;
    }
    for (int idx = 0; idx < data_size_y; ++idx) {
        y->rows_[0][idx] = rand() % 1000 - 500;
    }
    for (int idx = 0; idx < data_size_z; ++idx) {
        z->rows_[0][idx] = 0;
    }

    i = 0;
    j = 0;
    k = 0;
    s = 0;
    v = 0;
}