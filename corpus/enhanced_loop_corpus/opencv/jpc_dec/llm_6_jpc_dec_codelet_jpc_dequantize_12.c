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
    jas_seqent_t *row_data;
    for (i = 0; i < ((x)->numrows_); ++i) {
        row_data = (x)->rows_[i];
        for (j = 0; j < ((x)->numcols_); ++j) {
            t = row_data[j];
            if (t) {
                t = ((jpc_fix_t)((((jpc_fix_big_t)(t)) * ((jpc_fix_big_t)(absstepsize))) >> (13)));
            } else {
                t = 0;
            }
            row_data[j] = t;
        }
    }
}
