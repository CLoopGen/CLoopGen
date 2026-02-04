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

jas_seq_t *x;
int m;
jas_seq_t *z;
int i;

static jas_seqent_t *data_pool_x = NULL;
static jas_seqent_t *data_pool_z = NULL;
static jas_seqent_t **rows_pool_x = NULL;
static jas_seqent_t **rows_pool_z = NULL;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // ~16MB of data for ~0.01 sec runtime estimate
    
    // Allocate large contiguous blocks for data and row pointers
    data_pool_x = calloc(data_size, sizeof(jas_seqent_t));
    data_pool_z = calloc(data_size, sizeof(jas_seqent_t));
    rows_pool_x = calloc(65536, sizeof(jas_seqent_t*));
    rows_pool_z = calloc(65536, sizeof(jas_seqent_t*));

    if (!data_pool_x || !data_pool_z || !rows_pool_x || !rows_pool_z) {
        exit(1);
    }

    // Set up x matrix
    x = malloc(sizeof(jas_matrix_t));
    x->xstart_ = 0;
    x->ystart_ = 0;
    x->numrows_ = 1;
    x->numcols_ = (int_fast32_t)(data_size / 2);
    x->xend_ = x->numcols_;
    x->yend_ = 1;
    x->maxrows_ = 1;
    x->datasize_ = x->numcols_;
    x->data_ = data_pool_x;
    x->rows_ = rows_pool_x;
    x->rows_[0] = x->data_;

    // Set up z matrix
    z = malloc(sizeof(jas_matrix_t));
    z->xstart_ = 0;
    z->ystart_ = 0;
    z->numrows_ = 1;
    z->numcols_ = (int_fast32_t)(data_size / 2);
    z->xend_ = z->numcols_;
    z->yend_ = 1;
    z->maxrows_ = 1;
    z->datasize_ = z->numcols_;
    z->data_ = data_pool_z;
    z->rows_ = rows_pool_z;
    z->rows_[0] = z->data_;

    // Initialize m to a reasonable modulus (must be > 0)
    m = 7;

    // Ensure that z->xend_ is at least z->xstart_ to avoid underflow
    // and that accesses into x via (i/m - x->xstart_) are in bounds
    // We set x->numcols_ and z->numcols_ such that i/m < x->numcols_
    // when i < z->numcols_. With m=7 and both sizes ~8M, this holds.
}