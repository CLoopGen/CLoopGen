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

typedef jas_matrix_t jas_seq2d_t;

extern jas_seq2d_t *x;
extern jas_matrix_t *y;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    jas_seqent_t **xrows = x->rows_;
    jas_seqent_t **yrows = y->rows_;
    int_fast32_t numrows = x->numrows_;
    int_fast32_t numcols = x->numcols_;
    for (i = 0; i < numrows; ++i) {
        jas_seqent_t *xrow = xrows[i];
        jas_seqent_t *yrow = yrows[i];
        for (j = 0; j < numcols; ++j) {
            yrow[j] = xrow[j];
        }
    }
}
