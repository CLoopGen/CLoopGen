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
    const size_t target_data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec on modern CPU
    numcols = 1024;
    numrows = target_data_size / (numcols * sizeof(jpc_fix_t)) / 3; // 3 matrices
    if (numrows == 0) numrows = 1;
    
    size_t total_elements = numrows * numcols;

    c0 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    c1 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    c2 = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));

    jas_seqent_t* data0 = (jas_seqent_t*)calloc(total_elements, sizeof(jas_seqent_t));
    jas_seqent_t* data1 = (jas_seqent_t*)calloc(total_elements, sizeof(jas_seqent_t));
    jas_seqent_t* data2 = (jas_seqent_t*)calloc(total_elements, sizeof(jas_seqent_t));

    jas_seqent_t** rows0 = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));
    jas_seqent_t** rows1 = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));
    jas_seqent_t** rows2 = (jas_seqent_t**)calloc(numrows, sizeof(jas_seqent_t*));

    for (int i = 0; i < numrows; ++i) {
        rows0[i] = &data0[i * numcols];
        rows1[i] = &data1[i * numcols];
        rows2[i] = &data2[i * numcols];
    }

    c0->rows_ = rows0;
    c0->data_ = data0;
    c0->numrows_ = numrows;
    c0->numcols_ = numcols;
    c0->datasize_ = total_elements;

    c1->rows_ = rows1;
    c1->data_ = data1;
    c1->numrows_ = numrows;
    c1->numcols_ = numcols;
    c1->datasize_ = total_elements;

    c2->rows_ = rows2;
    c2->data_ = data2;
    c2->numrows_ = numrows;
    c2->numcols_ = numcols;
    c2->datasize_ = total_elements;

    for (size_t k = 0; k < total_elements; ++k) {
        data0[k] = (jpc_fix_t)(k % 256);
        data1[k] = (jpc_fix_t)((k + 1) % 256);
        data2[k] = (jpc_fix_t)((k + 2) % 256);
    }
}