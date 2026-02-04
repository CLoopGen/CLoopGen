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

extern jas_matrix_t *mat0;
extern jas_matrix_t *mat1;
extern int r0;
extern int c0;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive rows in mat1 starting from r0,
    // access every second row (stride of 2), wrapping within valid bounds.
    int stride = 2;
    int adjusted_r0 = r0 % (mat1->numrows_ / stride + 1);
    for (i = 0; i < mat0->numrows_; ++i) {
        int source_row = adjusted_r0 + i * stride;
        if (source_row >= mat1->numrows_) {
            source_row = mat1->numrows_ - 1; // clamp to last row if out of bounds
        }
        mat0->rows_[i] = mat1->rows_[source_row] + c0;
    }
}
