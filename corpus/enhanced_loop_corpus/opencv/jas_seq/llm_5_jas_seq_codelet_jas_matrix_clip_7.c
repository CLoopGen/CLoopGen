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
for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i, rowstart += rowstep) {
    data = rowstart;
    for (j = matrix->numcols_; j > 0; --j, ++data) {
        v = *data;
        *data = (v < minval) ? minval : ((v > maxval) ? maxval : v);
    }
}
}
