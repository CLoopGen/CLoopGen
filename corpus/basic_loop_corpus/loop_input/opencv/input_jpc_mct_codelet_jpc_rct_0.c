#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jas_seqent_t;
typedef int_fast32_t jpc_fix_t;

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
jpc_fix_t *c0p;
jpc_fix_t *c1p;
jpc_fix_t *c2p;

void init_vars() {
    numrows = 8192;
    numcols = 8192;

    size_t total_elements = (size_t)numrows * numcols;
    size_t data_size_bytes = total_elements * sizeof(jas_seqent_t);

    jas_seqent_t *data0 = (jas_seqent_t *)calloc(total_elements, sizeof(jas_seqent_t));
    jas_seqent_t *data1 = (jas_seqent_t *)calloc(total_elements, sizeof(jas_seqent_t));
    jas_seqent_t *data2 = (jas_seqent_t *)calloc(total_elements, sizeof(jas_seqent_t));

    jas_seqent_t **rows0 = (jas_seqent_t **)malloc(numrows * sizeof(jas_seqent_t *));
    jas_seqent_t **rows1 = (jas_seqent_t **)malloc(numrows * sizeof(jas_seqent_t *));
    jas_seqent_t **rows2 = (jas_seqent_t **)malloc(numrows * sizeof(jas_seqent_t *));

    for (int i = 0; i < numrows; ++i) {
        rows0[i] = &data0[i * numcols];
        rows1[i] = &data1[i * numcols];
        rows2[i] = &data2[i * numcols];
    }

    c0 = (jas_matrix_t *)malloc(sizeof(jas_matrix_t));
    c1 = (jas_matrix_t *)malloc(sizeof(jas_matrix_t));
    c2 = (jas_matrix_t *)malloc(sizeof(jas_matrix_t));

    c0->flags_ = 0;
    c0->xstart_ = 0;
    c0->ystart_ = 0;
    c0->xend_ = numcols - 1;
    c0->yend_ = numrows - 1;
    c0->numrows_ = numrows;
    c0->numcols_ = numcols;
    c0->rows_ = rows0;
    c0->maxrows_ = numrows;
    c0->data_ = data0;
    c0->datasize_ = total_elements;

    c1->flags_ = 0;
    c1->xstart_ = 0;
    c1->ystart_ = 0;
    c1->xend_ = numcols - 1;
    c1->yend_ = numrows - 1;
    c1->numrows_ = numrows;
    c1->numcols_ = numcols;
    c1->rows_ = rows1;
    c1->maxrows_ = numrows;
    c1->data_ = data1;
    c1->datasize_ = total_elements;

    c2->flags_ = 0;
    c2->xstart_ = 0;
    c2->ystart_ = 0;
    c2->xend_ = numcols - 1;
    c2->yend_ = numrows - 1;
    c2->numrows_ = numrows;
    c2->numcols_ = numcols;
    c2->rows_ = rows2;
    c2->maxrows_ = numrows;
    c2->data_ = data2;
    c2->datasize_ = total_elements;

    for (size_t idx = 0; idx < total_elements; ++idx) {
        data0[idx] = (rand() % 256) - 128;
        data1[idx] = (rand() % 256) - 128;
        data2[idx] = (rand() % 256) - 128;
    }

    c0p = 0;
    c1p = 0;
    c2p = 0;
    i = 0;
    j = 0;
}