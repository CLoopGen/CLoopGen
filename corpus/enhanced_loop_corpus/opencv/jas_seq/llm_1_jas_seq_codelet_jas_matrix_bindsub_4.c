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
    if (mat0->numrows_ > 0) {
        i = 0;
        for (; i < mat0->numrows_; ++i) {
            mat0->rows_[i] = mat1->rows_[r0 + i] + c0;
        }
    }
}
