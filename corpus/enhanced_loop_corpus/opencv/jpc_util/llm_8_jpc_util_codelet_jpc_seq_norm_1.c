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
    int start = (x)->xstart_;
    int end = (x)->xend_;
    for (i = start; i < end; i += 2) {
        jas_seqent_t val1 = (x)->rows_[0][i - start];
        jas_seqent_t val2 = (x)->rows_[0][i + 1 - start];
        s = s + ((jpc_fix_t)((((jpc_fix_big_t)(val1)) * ((jpc_fix_big_t)(val1))) >> (13)));
        s = s + ((jpc_fix_t)((((jpc_fix_big_t)(val2)) * ((jpc_fix_big_t)(val2))) >> (13)));
    }
}
