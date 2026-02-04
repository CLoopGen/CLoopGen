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

extern jas_matrix_t *c0;
extern jas_matrix_t *c1;
extern jas_matrix_t *c2;
extern int numrows;
extern int numcols;
extern int i;
extern int j;
extern jpc_fix_t *c0p;
extern jpc_fix_t *c1p;
extern jpc_fix_t *c2p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < numrows; ++i) {
    c0p = &(c0->rows_[i][0]);
    c1p = &(c1->rows_[i][0]);
    c2p = &(c2->rows_[i][0]);
    j = numcols;
    for (; j > 0; --j) {
        int r = *c0p;
        int g = *c1p;
        int b = *c2p;
        int y = (r + (g << 1) + b) >> 2;
        int u = b - g;
        int v = r - g;
        *c0p++ = y;
        *c1p++ = u;
        *c2p++ = v;
    }
}
}
