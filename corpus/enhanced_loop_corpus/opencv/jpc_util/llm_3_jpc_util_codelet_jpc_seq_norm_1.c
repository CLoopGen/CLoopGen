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



void loop() {
    int_fast32_t xstart = (x)->xstart_;
    int_fast32_t xend = (x)->xend_;
    jas_seqent_t *base_row = (x)->rows_[0];
    int stride = 2; // Strided access: process every 2nd element

    jpc_fix_t local_s = s;

    for (i = xstart; i < xend; i += stride) {
        int idx = i - xstart;
        jas_seqent_t val = base_row[idx];
        local_s = local_s + ((jpc_fix_t)(((jpc_fix_big_t)val * val) >> 13));
    }

    // Handle any remaining element if range is odd
    if ((xend - xstart) % 2 != 0) {
        int last_idx = (xend - 1) - xstart;
        jas_seqent_t val = base_row[last_idx];
        local_s = local_s + ((jpc_fix_t)(((jpc_fix_big_t)val * val) >> 13));
    }

    s = local_s;
}
