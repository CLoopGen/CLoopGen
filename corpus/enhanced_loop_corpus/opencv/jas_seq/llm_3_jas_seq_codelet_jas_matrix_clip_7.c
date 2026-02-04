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



void loop() {
    // Variant 2: Strided memory access with reversed row traversal and alternating column directions per row
    for (i = 0; i < matrix->numrows_; ++i) {
        jas_seqent_t *rowstart = matrix->rows_[matrix->numrows_ - 1 - i]; // Reverse row order
        int stride = (i % 2 == 0) ? 1 : -1; // Alternate direction: left-to-right, then right-to-left
        int start_col = (i % 2 == 0) ? 0 : matrix->numcols_ - 1;
        int end_col = (i % 2 == 0) ? matrix->numcols_ : -1;
        
        for (int j = start_col; (stride == 1) ? (j < end_col) : (j > end_col); j += stride) {
            data = rowstart + j;
            v = *data;
            if (v < minval) {
                *data = minval;
            } else if (v > maxval) {
                *data = maxval;
            }
        }
    }
}
