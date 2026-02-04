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
for (i = 0; i < numrows; i += 2) {
    c0p = (&(c0)->rows_[i][0]);
    c1p = (&(c1)->rows_[i][0]);
    c2p = (&(c2)->rows_[i][0]);
    if (i + 1 < numrows) {
        for (j = 0; j < numcols; ++j) {
            y = c0p[j]; u = c1p[j]; v = c2p[j];
            r = y + ((jpc_fix_t)((11483LL * v) >> 13));
            g = y + ((jpc_fix_t)(((-2260LL * u - 4704LL * v)) >> 13));
            b = y + ((jpc_fix_t)((9248LL * u) >> 13));
            c0p[j] = r; c1p[j] = g; c2p[j] = b;

            y = c0->rows_[i+1][j]; u = c1->rows_[i+1][j]; v = c2->rows_[i+1][j];
            r = y + ((jpc_fix_t)((11483LL * v) >> 13));
            g = y + ((jpc_fix_t)(((-2260LL * u - 4704LL * v)) >> 13));
            b = y + ((jpc_fix_t)((9248LL * u) >> 13));
            c0->rows_[i+1][j] = r; c1->rows_[i+1][j] = g; c2->rows_[i+1][j] = b;
        }
    } else {
        for (j = numcols; j > 0; --j) {
            y = *c0p; u = *c1p; v = *c2p;
            r = y + ((jpc_fix_t)((11483LL * v) >> 13));
            g = y + ((jpc_fix_t)(((-2260LL * u - 4704LL * v)) >> 13));
            b = y + ((jpc_fix_t)((9248LL * u) >> 13));
            *c0p++ = r; *c1p++ = g; *c2p++ = b;
        }
    }
}
}
