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

jas_matrix_t *x;
jpc_fix_t absstepsize;
int i;
int j;
int t;

void init_vars() {
    const int numrows = 4096;
    const int numcols = 4096;

    x = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    x->numrows_ = numrows;
    x->numcols_ = numcols;
    x->maxrows_ = numrows;
    x->datasize_ = numrows * numcols;

    x->data_ = (jas_seqent_t*)calloc(x->datasize_, sizeof(jas_seqent_t));
    x->rows_ = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));

    for (int i = 0; i < numrows; ++i) {
        x->rows_[i] = &x->data_[i * numcols];
    }

    for (int i = 0; i < numrows; ++i) {
        for (int j = 0; j < numcols; ++j) {
            x->rows_[i][j] = (i + j) % 1000;
        }
    }

    absstepsize = 8192;
}