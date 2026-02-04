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

    // Increase trip count artificially by splitting each shift into multiple smaller shifts
    // Instead of one left-shift by n, apply n unit left-shifts, increasing complexity from O(N) to O(N*n)
    for (i = matrix->numrows_, rowstart = matrix->rows_[0]; i > 0; --i, ++rowstart) {
        for (j = matrix->numcols_, data = rowstart; j > 0; --j, ++data) {
            int shift_step;
            for (shift_step = 0; shift_step < n; ++shift_step) {
                *data <<= 1;
            }
        }
    }
}
