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
            r = c0p[j];      g = c1p[j];      b = c2p[j];
            y = ((jpc_fix_t)((((jpc_fix_big_t)(r * 2456 + g * 4802 + b * 935)) >> 13)));
            u = ((jpc_fix_t)((((jpc_fix_big_t)(r * -1380 + g * -2710 + b * 4096)) >> 13)));
            v = ((jpc_fix_t)((((jpc_fix_big_t)(r * 4096 + g * -3428 + b * -666)) >> 13)));
            c0->rows_[i][j] = y;
            c1->rows_[i][j] = u;
            c2->rows_[i][j] = v;

            r = c0->rows_[i+1][j];
            g = c1->rows_[i+1][j];
            b = c2->rows_[i+1][j];
            y = ((jpc_fix_t)((((jpc_fix_big_t)(r * 2456 + g * 4802 + b * 935)) >> 13)));
            u = ((jpc_fix_t)((((jpc_fix_big_t)(r * -1380 + g * -2710 + b * 4096)) >> 13)));
            v = ((jpc_fix_t)((((jpc_fix_big_t)(r * 4096 + g * -3428 + b * -666)) >> 13)));
            c0->rows_[i+1][j] = y;
            c1->rows_[i+1][j] = u;
            c2->rows_[i+1][j] = v;
        }
    } else {
        for (j = 0; j < numcols; ++j) {
            r = c0p[j];      g = c1p[j];      b = c2p[j];
            y = ((jpc_fix_t)((((jpc_fix_big_t)(r * 2456 + g * 4802 + b * 935)) >> 13)));
            u = ((jpc_fix_t)((((jpc_fix_big_t)(r * -1380 + g * -2710 + b * 4096)) >> 13)));
            v = ((jpc_fix_t)((((jpc_fix_big_t)(r * 4096 + g * -3428 + b * -666)) >> 13)));
            c0->rows_[i][j] = y;
            c1->rows_[i][j] = u;
            c2->rows_[i][j] = v;
        }
    }
}
}
