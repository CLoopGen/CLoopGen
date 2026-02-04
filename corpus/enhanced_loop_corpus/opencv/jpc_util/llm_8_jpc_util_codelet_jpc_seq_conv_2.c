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
extern jas_seq_t *y;
extern int i;
extern int j;
extern int k;
extern jas_seq_t *z;
extern jpc_fix_t s;
extern jpc_fix_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = ((z)->xstart_); i < ((z)->xend_); i += 2) {
    s = ((jpc_fix_t)((0) << (13)));
    for (j = ((y)->xstart_); j < ((y)->xend_) - 1; j += 2) {
        k = i - j;
        if (k < ((x)->xstart_) || k >= ((x)->xend_)) {
            v = ((jpc_fix_t)(0));
        } else {
            v = ((x)->rows_[0][(k) - (x)->xstart_]);
        }
        s = ((s) + (((jpc_fix_t)((((jpc_fix_big_t)(((y)->rows_[0][(j) - (y)->xstart_]))) * ((jpc_fix_big_t)(v))) >> (13)))));
        k = i - j - 1;
        if (k < ((x)->xstart_) || k >= ((x)->xend_)) {
            v = ((jpc_fix_t)(0));
        } else {
            v = ((x)->rows_[0][(k) - (x)->xstart_]);
        }
        s = ((s) + (((jpc_fix_t)((((jpc_fix_big_t)(((y)->rows_[0][(j + 1) - (y)->xstart_]))) * ((jpc_fix_big_t)(v))) >> (13)))));
    }
    *(&(z)->rows_[0][(i) - (z)->xstart_]) = s;
    if (i + 1 < (z)->xend_) {
        *(&(z)->rows_[0][(i + 1) - (z)->xstart_]) = s; 
    }
}
}
