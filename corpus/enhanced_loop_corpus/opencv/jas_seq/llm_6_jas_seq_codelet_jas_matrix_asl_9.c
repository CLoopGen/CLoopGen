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
    // Variant 1: Introduce loop-carried dependency (WAW) via temporary accumulation
    // Instead of shifting each element independently, accumulate shifted values in a temp variable
    // that depends on the previous iteration's result (artificial WAW + RAW dependency).
    jas_seqent_t temp = 0;
    for (i = 0; i < matrix->numrows_; ++i) {
        rowstart = matrix->rows_[i];
        temp = 0; // Reset per row to limit dependency scope
        for (j = 0; j < matrix->numcols_; ++j) {
            data = &rowstart[j];
            temp = (*data << n) | (temp >> 1); // RAW: uses previous temp; WAW: temp overwritten
            *data = temp; // Write dependent on computed value
        }
    }
}
