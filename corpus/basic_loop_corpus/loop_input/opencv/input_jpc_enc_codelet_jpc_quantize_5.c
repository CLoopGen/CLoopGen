#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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

jas_matrix_t *data;
jpc_fix_t stepsize;
int i;
int j;
jpc_fix_t t;

void init_vars() {
    const size_t target_size_bytes = 64 * 1024 * 1024; // ~64 MB of data
    const size_t element_size = sizeof(jas_seqent_t);
    const size_t total_elements = target_size_bytes / element_size;
    data = (jas_matrix_t*)calloc(1, sizeof(jas_matrix_t));
    if (!data) exit(1);

    data->numrows_ = (int_fast32_t)sqrt(total_elements);
    data->numcols_ = (int_fast32_t)(total_elements / data->numrows_);
    data->datasize_ = data->numrows_ * data->numcols_;
    data->maxrows_ = data->numrows_;

    data->data_ = (jas_seqent_t*)calloc(data->datasize_, sizeof(jas_seqent_t));
    if (!data->data_) exit(1);

    data->rows_ = (jas_seqent_t**)calloc(data->numrows_, sizeof(jas_seqent_t*));
    if (!data->rows_) exit(1);

    for (int_fast32_t r = 0; r < data->numrows_; ++r) {
        data->rows_[r] = &(data->data_[r * data->numcols_]);
    }

    stepsize = 8192; // reasonable non-power-of-two divisor to avoid division by zero and ensure work in loop

    // Initialize data with non-zero values to ensure meaningful computation
    for (int_fast32_t idx = 0; idx < data->datasize_; ++idx) {
        data->data_[idx] = (jas_seqent_t)(idx % 10000);
    }
}