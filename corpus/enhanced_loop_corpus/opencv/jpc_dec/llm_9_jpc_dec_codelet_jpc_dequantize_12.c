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

extern jas_matrix_t *x;
extern jpc_fix_t absstepsize;
extern int i;
extern int j;
extern int t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
int limit_i = (x)->numrows_;
int limit_j = (x)->numcols_ - 1;

for (i = 0; i < limit_i; i += 1) {
    for (j = 0; j < limit_j; j += stride) {
        int j1 = j;
        int j2 = j + 1;

        t = ((x)->rows_[i][j1]);
        if (t) {
            t = ((jpc_fix_t)((((jpc_fix_big_t)(t)) * ((jpc_fix_big_t)(absstepsize))) >> (13)));
        } else {
            t = 0;
        }
        ((x)->rows_[i][j1] = (t));

        if (j2 < (x)->numcols_) {
            t = ((x)->rows_[i][j2]);
            if (t) {
                t = ((jpc_fix_t)((((jpc_fix_big_t)(t)) * ((jpc_fix_big_t)(absstepsize))) >> (13)));
            } else {
                t = 0;
            }
            ((x)->rows_[i][j2] = (t));
        }
    }
}
}
