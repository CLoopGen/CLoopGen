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
    int stride = 2;
    for (i = 0; i < x->numrows_; i += stride) {
        for (j = 0; j < x->numcols_; ++j) {
            if (i + 1 < x->numrows_) {
                y->rows_[i][j] = x->rows_[i][j] + x->rows_[i+1][j]; // Fused row operation, reduced trip count with increased per-iteration work
            } else {
                y->rows_[i][j] = x->rows_[i][j];
            }
        }
    }
}
