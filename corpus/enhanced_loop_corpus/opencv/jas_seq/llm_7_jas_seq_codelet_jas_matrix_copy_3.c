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

extern jas_matrix_t *x;
extern jas_matrix_t *y;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int_fast32_t total_elements = x->numrows_ * x->numcols_;
    jas_seqent_t* y_data = &y->rows_[0][0];
    jas_seqent_t* x_data = &x->rows_[0][0];
    for (int_fast32_t idx = 0; idx < total_elements; ++idx) {
        y_data[idx] = x_data[idx];
    }
}
