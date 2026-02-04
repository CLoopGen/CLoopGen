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



void loop(){
    jas_seqent_t **rows0 = mat0->rows_;
    jas_seqent_t **rows1 = mat1->rows_;
    int_fast32_t base_row = r0;
    int_fast32_t col_offset = c0;
    int_fast32_t numrows = mat0->numrows_;
    for (i = 0; i < numrows; ++i) {
        jas_seqent_t *src_row = rows1[base_row + i];
        rows0[i] = src_row + col_offset;
    }
}
