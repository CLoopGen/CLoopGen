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
    int i, j, t;
    int_fast32_t numrows = (x)->numrows_;
    int_fast32_t numcols = (x)->numcols_;
    jas_seqent_t **rows = (x)->rows_;
    jpc_fix_t stepsize = absstepsize;
    int stride = 2;

    for (i = 0; i < numrows; ++i) {
        jas_seqent_t *row = rows[i];
        for (j = 0; j < numcols; j += stride) {
            // Unroll factor of 2 with strided access
            int j1 = j;
            int j2 = j + 1;
            if (j1 < numcols) {
                t = row[j1];
                if (t) {
                    t = ((jpc_fix_t)((((jpc_fix_big_t)(t)) * ((jpc_fix_big_t)(stepsize))) >> 13));
                } else {
                    t = 0;
                }
                row[j1] = t;
            }
            if (j2 < numcols) {
                t = row[j2];
                if (t) {
                    t = ((jpc_fix_t)((((jpc_fix_big_t)(t)) * ((jpc_fix_big_t)(stepsize))) >> 13));
                } else {
                    t = 0;
                }
                row[j2] = t;
            }
        }
    }
}
