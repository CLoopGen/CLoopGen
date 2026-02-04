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
jpc_fix_t s;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of data

    x = (jas_seq_t*)calloc(1, sizeof(jas_seq_t));
    x->xstart_ = 0;
    x->xend_ = data_size;
    x->numcols_ = data_size;
    x->numrows_ = 1;
    x->maxrows_ = 1;

    x->data_ = (jas_seqent_t*)calloc(data_size, sizeof(jas_seqent_t));
    x->rows_ = (jas_seqent_t**)calloc(1, sizeof(jas_seqent_t*));
    x->rows_[0] = x->data_;

    for (size_t idx = 0; idx < data_size; ++idx) {
        x->data_[idx] = (jas_seqent_t)(idx & 0x7FFF);
    }

    s = 0;
    i = 0;
}