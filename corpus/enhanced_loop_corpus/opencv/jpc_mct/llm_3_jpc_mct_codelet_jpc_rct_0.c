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
for (i = 0; i < numrows; i++) {
    c0p = &(c0)->data_[i * (c0)->numcols_];
    c1p = &(c1)->data_[i * (c1)->numcols_];
    c2p = &(c2)->data_[i * (c2)->numcols_];
    for (j = 0; j < numcols; j += 2) {
        int r0, g0, b0, y0, u0, v0;
        int r1, g1, b1, y1, u1, v1;
        r0 = c0p[j]; g0 = c1p[j]; b0 = c2p[j];
        r1 = (j + 1 < numcols) ? c0p[j+1] : r0;
        g1 = (j + 1 < numcols) ? c1p[j+1] : g0;
        b1 = (j + 1 < numcols) ? c2p[j+1] : b0;

        y0 = (r0 + (g0 << 1) + b0) >> 2;
        u0 = b0 - g0;
        v0 = r0 - g0;

        y1 = (r1 + (g1 << 1) + b1) >> 2;
        u1 = b1 - g1;
        v1 = r1 - g1;

        c0p[j] = y0; c1p[j] = u0; c2p[j] = v0;
        if (j + 1 < numcols) {
            c0p[j+1] = y1;
            c1p[j+1] = u1;
            c2p[j+1] = v1;
        }
    }
}
}
