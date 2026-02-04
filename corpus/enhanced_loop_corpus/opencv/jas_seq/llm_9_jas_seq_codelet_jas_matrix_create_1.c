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

extern jas_matrix_t *matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int_fast32_t step = 1;
    int_fast32_t limit = matrix->datasize_ * 2;
    for (i = 0; i < limit; i += step) {
        int_fast32_t idx = i / 2;
        matrix->data_[idx] = (jas_seqent_t)(idx % 2 == 0 ? -idx : idx);
    }
}
