#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jas_seqent_t;
typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

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

jas_matrix_t *c0;
jas_matrix_t *c1;
jas_matrix_t *c2;
int numrows;
int numcols;
int i;
int j;
jpc_fix_t r;
jpc_fix_t g;
jpc_fix_t b;
jpc_fix_t y;
jpc_fix_t u;
jpc_fix_t v;
jpc_fix_t *c0p;
jpc_fix_t *c1p;
jpc_fix_t *c2p;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01s on modern CPU)
    numcols = 1024;
    numrows = total_data_size / (numcols * 3 * sizeof(jpc_fix_t));
    if (numrows == 0) numrows = 1;
    size_t actual_data_size = numrows * numcols * sizeof(jpc_fix_t);

    c0 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    c1 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    c2 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));

    c0->numrows_ = numrows;
    c0->numcols_ = numcols;
    c1->numrows_ = numrows;
    c1->numcols_ = numcols;
    c2->numrows_ = numrows;
    c2->numcols_ = numcols;

    c0->data_ = (jas_seqent_t*)calloc(actual_data_size, 1);
    c1->data_ = (jas_seqent_t*)calloc(actual_data_size, 1);
    c2->data_ = (jas_seqent_t*)calloc(actual_data_size, 1);

    c0->datasize_ = numrows * numcols;
    c1->datasize_ = numrows * numcols;
    c2->datasize_ = numrows * numcols;

    c0->rows_ = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));
    c1->rows_ = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));
    c2->rows_ = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));

    for (int i = 0; i < numrows; ++i) {
        c0->rows_[i] = &c0->data_[i * numcols];
        c1->rows_[i] = &c1->data_[i * numcols];
        c2->rows_[i] = &c2->data_[i * numcols];
    }

    for (int i = 0; i < numrows * numcols; ++i) {
        c0->data_[i] = rand() % 256;
        c1->data_[i] = rand() % 256;
        c2->data_[i] = rand() % 256;
    }
}