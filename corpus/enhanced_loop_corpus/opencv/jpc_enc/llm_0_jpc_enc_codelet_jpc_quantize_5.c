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

typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jas_matrix_t *data;
extern jpc_fix_t stepsize;
extern int i;
extern int j;
extern jpc_fix_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ((data)->numrows_); ++i) {
    for (j = 0; j < ((data)->numcols_); ++j) {
        t = ((data)->rows_[i][j]);
        {
            if (t < 0) {
                t = (-(((jpc_fix_t)((((jpc_fix_big_t)((-(t)))) << (13)) / (stepsize)))));
            } else {
                t = ((jpc_fix_t)((((jpc_fix_big_t)(t)) << (13)) / (stepsize)));
            }
        }
        ((data)->rows_[i][j] = (t));
    }
}
}

