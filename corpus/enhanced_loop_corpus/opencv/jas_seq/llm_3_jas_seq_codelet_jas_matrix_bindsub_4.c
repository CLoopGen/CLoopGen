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
    // Variant 2: Consecutive Memory Access with Data Prefetching
    // Reorder access to improve spatial locality by ensuring sequential
    // reads from mat1's data_ array via a flat index, simulating linear traversal.
    jas_seqent_t* base_data = mat1->data_;
    int_fast32_t row_offset = r0 * mat1->numcols_;
    int_fast32_t col_offset = c0;
    for (i = 0; i < mat0->numrows_; ++i) {
        int flat_index = row_offset + col_offset;
        // Simulate consecutive access pattern in underlying data
        mat0->rows_[i] = &base_data[flat_index];
        row_offset += mat1->numcols_; // move to next row in mat1
    }
}
