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
    // Eliminate write-after-write (WAW) and write-after-read (WAR) hazards by reordering independent operations
    // Unroll by 2 for increased ILP and reduced loop-carried dependencies
    j = numcols;
    while (j >= 2) {
        // Process two elements per iteration with separated read/write phases to reduce intra-loop data coupling
        int y1 = c0p[0], u1 = c1p[0], v1 = c2p[0];
        int y2 = c0p[1], u2 = c1p[1], v2 = c2p[1];

        int g1 = y1 - ((u1 + v1) >> 2);
        int g2 = y2 - ((u2 + v2) >> 2);
        int r1 = v1 + g1, r2 = v2 + g2;
        int b1 = u1 + g1, b2 = u2 + g2;

        c0p[0] = r1; c1p[0] = g1; c2p[0] = b1;
        c0p[1] = r2; c1p[1] = g2; c2p[1] = b2;

        c0p += 2; c1p += 2; c2p += 2;
        j -= 2;
    }
    // Handle remaining element if any
    if (j == 1) {
        int y = *c0p, u = *c1p, v = *c2p;
        int g = y - ((u + v) >> 2);
        int r = v + g;
        int b = u + g;
        *c0p++ = r;
        *c1p++ = g;
        *c2p++ = b;
    }
}
}
