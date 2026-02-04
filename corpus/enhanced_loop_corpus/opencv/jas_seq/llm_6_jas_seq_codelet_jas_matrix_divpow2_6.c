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
    int rowstep = (matrix->numrows_ > 1) ? matrix->rows_[1] - matrix->rows_[0] : matrix->numcols_;
    for (i = 0; i < matrix->numrows_; ++i) {
        rowstart = matrix->rows_[i];
        for (j = 0; j < matrix->numcols_; ++j) {
            data = &rowstart[j];
            jas_seqent_t val = *data;
            jas_seqent_t abs_val = (val >= 0) ? val : -val;
            jas_seqent_t shifted_abs = abs_val >> n;
            *data = (val >= 0) ? shifted_abs : -shifted_abs;
        }
    }
}
