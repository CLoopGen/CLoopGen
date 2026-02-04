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

static jas_seqent_t* data0 = NULL;
static jas_seqent_t* data1 = NULL;
static jas_seqent_t* data2 = NULL;
static jas_seqent_t** rows0 = NULL;
static jas_seqent_t** rows1 = NULL;
static jas_seqent_t** rows2 = NULL;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // ~64MB total data to hit ~0.01s runtime
    const size_t element_size = sizeof(jas_seqent_t);
    const size_t total_elements = target_bytes / (3 * element_size); // three matrices
    numcols = (int)(total_elements > 10000 ? 4096 : 256); // reasonable column count
    numrows = (int)(total_elements / numcols);
    if (numrows < 1) numrows = 1;

    size_t data_size = (size_t)numrows * numcols;

    data0 = (jas_seqent_t*)calloc(data_size, element_size);
    data1 = (jas_seqent_t*)calloc(data_size, element_size);
    data2 = (jas_seqent_t*)calloc(data_size, element_size);
    rows0 = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));
    rows1 = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));
    rows2 = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));

    for (int i = 0; i < numrows; ++i) {
        rows0[i] = &data0[i * numcols];
        rows1[i] = &data1[i * numcols];
        rows2[i] = &data2[i * numcols];
    }

    c0 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    c1 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    c2 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));

    c0->rows_ = rows0;
    c0->data_ = data0;
    c0->numrows_ = numrows;
    c0->numcols_ = numcols;
    c0->datasize_ = data_size;
    c0->maxrows_ = numrows;
    c0->xstart_ = 0;
    c0->ystart_ = 0;
    c0->xend_ = numcols;
    c0->yend_ = numrows;
    c0->flags_ = 0;

    c1->rows_ = rows1;
    c1->data_ = data1;
    c1->numrows_ = numrows;
    c1->numcols_ = numcols;
    c1->datasize_ = data_size;
    c1->maxrows_ = numrows;
    c1->xstart_ = 0;
    c1->ystart_ = 0;
    c1->xend_ = numcols;
    c1->yend_ = numrows;
    c1->flags_ = 0;

    c2->rows_ = rows2;
    c2->data_ = data2;
    c2->numrows_ = numrows;
    c2->numcols_ = numcols;
    c2->datasize_ = data_size;
    c2->maxrows_ = numrows;
    c2->xstart_ = 0;
    c2->ystart_ = 0;
    c2->xend_ = numcols;
    c2->yend_ = numrows;
    c2->flags_ = 0;

    for (size_t k = 0; k < data_size; ++k) {
        data0[k] = (jas_seqent_t)(rand() % 256 - 128);
        data1[k] = (jas_seqent_t)(rand() % 256 - 128);
        data2[k] = (jas_seqent_t)(rand() % 256 - 128);
    }
}