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
    c0p = (&(c0)->rows_[i][0]);
    c1p = (&(c1)->rows_[i][0]);
    c2p = (&(c2)->rows_[i][0]);
    // Eliminate write-write (WAW) and read-after-write (RAW) dependencies by unrolling two elements
    // Process two pixels per iteration to reduce loop-carried dependencies and expose parallelism
    j = numcols;
    while (j >= 2) {
        int r0, g0, b0, y0, u0, v0;
        int r1, g1, b1, y1, u1, v1;

        r0 = c0p[0]; g0 = c1p[0]; b0 = c2p[0];
        r1 = c0p[1]; g1 = c1p[1]; b1 = c2p[1];

        y0 = (r0 + (g0 << 1) + b0) >> 2;
        u0 = b0 - g0;
        v0 = r0 - g0;

        y1 = (r1 + (g1 << 1) + b1) >> 2;
        u1 = b1 - g1;
        v1 = r1 - g1;

        c0p[0] = y0; c1p[0] = u0; c2p[0] = v0;
        c0p[1] = y1; c1p[1] = u1; c2p[1] = v1;

        c0p += 2; c1p += 2; c2p += 2;
        j -= 2;
    }
    // Handle odd column count
    if (j == 1) {
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
