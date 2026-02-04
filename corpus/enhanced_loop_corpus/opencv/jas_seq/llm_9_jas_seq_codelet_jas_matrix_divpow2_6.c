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
extern int n;
extern int i;
extern int j;
extern jas_seqent_t *rowstart;
extern int rowstep;
extern jas_seqent_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    jas_seqent_t *rowstart;
    jas_seqent_t *data;
    int unroll_factor = 4;
    int numcols = matrix->numcols_;
    int remainder = numcols % unroll_factor;
    for (i = 0; i < matrix->numrows_; ++i) {
        rowstart = matrix->rows_[i];
        j = 0;
        for (; j < numcols - remainder; j += unroll_factor) {
            data = rowstart + j;
            *data = (*data >= 0) ? (*data >> n) : (-((-(*data)) >> n));
            *(data + 1) = (*(data + 1) >= 0) ? (*(data + 1) >> n) : (-((-(*(data + 1))) >> n));
            *(data + 2) = (*(data + 2) >= 0) ? (*(data + 2) >> n) : (-((-(*(data + 2))) >> n));
            *(data + 3) = (*(data + 3) >= 0) ? (*(data + 3) >> n) : (-((-(*(data + 3))) >> n));
        }
        for (; j < numcols; ++j) {
            data = rowstart + j;
            *data = (*data >= 0) ? (*data >> n) : (-((-(*data)) >> n));
        }
    }
}
