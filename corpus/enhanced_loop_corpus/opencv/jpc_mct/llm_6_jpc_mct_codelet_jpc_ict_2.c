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

extern jas_matrix_t *c0;
extern jas_matrix_t *c1;
extern jas_matrix_t *c2;
extern int numrows;
extern int numcols;
extern int i;
extern int j;
extern jpc_fix_t r;
extern jpc_fix_t g;
extern jpc_fix_t b;
extern jpc_fix_t y;
extern jpc_fix_t u;
extern jpc_fix_t v;
extern jpc_fix_t *c0p;
extern jpc_fix_t *c1p;
extern jpc_fix_t *c2p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < numrows; ++i) {
    c0p = &(c0)->rows_[i][0];
    c1p = &(c1)->rows_[i][0];
    c2p = &(c2)->rows_[i][0];
    for (j = numcols; j > 0; --j) {
        r = *c0p;
        g = *c1p;
        b = *c2p;
        y = ((((((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((0.29899999999999999) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(r))) >> (13)))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((0.58699999999999997) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(g))) >> (13)))))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((0.114) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(b))) >> (13)))));
        u = ((((((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((-0.16875000000000001) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(r))) >> (13)))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((-0.33126) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(g))) >> (13)))))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((0.5) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(b))) >> (13)))));
        v = ((((((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((0.5) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(r))) >> (13)))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((-0.41869000000000001) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(g))) >> (13)))))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((-0.081309999999999993) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(b))) >> (13)))));
        *c0p = y;
        *c1p = u;
        *c2p = v;
        c0p++;
        c1p++;
        c2p++;
    }
}
}
