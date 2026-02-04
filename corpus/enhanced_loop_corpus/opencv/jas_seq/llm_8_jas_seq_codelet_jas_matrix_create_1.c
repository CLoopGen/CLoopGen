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
    int_fast32_t size = matrix->datasize_;
    for (i = 0; i < size; i += 4) {
        if (i < size) matrix->data_[i] = 0;
        if (i + 1 < size) matrix->data_[i + 1] = 0;
        if (i + 2 < size) matrix->data_[i + 2] = 0;
        if (i + 3 < size) matrix->data_[i + 3] = 0;
    }
}
