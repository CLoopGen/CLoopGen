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

typedef jas_matrix_t jas_seq_t;

typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jas_seq_t *x;
extern jpc_fix_t s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; ++j) {
        for (i = ((x)->xstart_); i < ((x)->xend_); i++) {
            s = ((s) + (((jpc_fix_t)((((jpc_fix_big_t)(((x)->rows_[0][(i) - (x)->xstart_]))) * ((jpc_fix_big_t)(((x)->rows_[0][(i) - (x)->xstart_])))) >> (13)))));
        }
    }
}
