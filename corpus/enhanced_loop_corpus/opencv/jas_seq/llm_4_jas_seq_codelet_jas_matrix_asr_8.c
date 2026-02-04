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
    if (matrix->numrows_ <= 0 || matrix->numcols_ <= 0) {
        return;
    }
    for (i = 0; i < matrix->numrows_; ++i) {
        rowstart = matrix->rows_[i];
        rowstep = (i == 0) ? 1 : rowstep; // dummy assignment to keep rowstep in scope
        for (j = 0; j < matrix->numcols_; ++j) {
            data = rowstart + j;
            if (*data != 0) {
                *data >>= n;
            }
        }
    }
}
