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
extern jas_seqent_t val;
extern int i;
extern int j;
extern jas_seqent_t *rowstart;
extern int rowstep;
extern jas_seqent_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with reversed row traversal and stride skipping every other element
    int stride = 2; // Access every second element
    for (i = 0; i < matrix->numrows_; ++i) {
        jas_seqent_t *rowstart = matrix->rows_[matrix->numrows_ - 1 - i]; // Reverse row order
        for (j = 0; j < matrix->numcols_; j += stride) {
            if (j + 1 < matrix->numcols_) {
                rowstart[j + 1] = val; // Write to odd positions in each row
            }
        }
    }
}
