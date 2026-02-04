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
    for (j = 0; j < numcols; ++j) {
        int idx = i * numcols + j;
        y = c0->data_[idx];
        u = c1->data_[idx];
        v = c2->data_[idx];
        r = ((y) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((1.4019999999999999) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(v))) >> (13)))));
        g = ((((y) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((-0.3441299999999999) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(u))) >> (13)))))) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((-0.71414) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(v))) >> (13)))));
        b = ((y) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((1.772) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(u))) >> (13)))));
        c0->data_[idx] = r;
        c1->data_[idx] = g;
        c2->data_[idx] = b;
    }
}
}
