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
extern jas_seqent_t minval;
extern jas_seqent_t maxval;
extern int i;
extern int j;
extern jas_seqent_t v;
extern jas_seqent_t *rowstart;
extern jas_seqent_t *data;
extern int rowstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    jas_seqent_t v;
    jas_seqent_t *data;
    jas_seqent_t *rowstart;
    int rowstep = 1; // Default stride

    for (i = 0; i < matrix->numrows_; ++i) {
        rowstart = matrix->rows_[i];
        for (j = 0; j < matrix->numcols_; ++j) {
            data = &rowstart[j * rowstep];
            v = *data;
            if (v < minval) {
                *data = minval;
            } else if (v > maxval) {
                *data = maxval;
            }
        }
    }
}
