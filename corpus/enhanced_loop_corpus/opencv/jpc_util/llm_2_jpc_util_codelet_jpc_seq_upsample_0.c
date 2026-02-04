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

extern jas_seq_t *x;
extern int m;
extern jas_seq_t *z;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with precomputed base pointer and offset
    jas_seqent_t *z_row_base = (z)->rows_[0] - (z)->xstart_;
    jas_seqent_t *x_row_base = (x)->rows_[0] - (x)->xstart_;
    int_fast32_t start = (z)->xstart_;
    int_fast32_t end = (z)->xend_;
    int shift_val = (jpc_fix_t)((0) << (13));

    for (i = start; i < end; i++) {
        int mod;
        if (i < 0) {
            int neg_i_mod = (-i) % m;
            mod = neg_i_mod ? (m - neg_i_mod) : 0;
        } else {
            mod = i % m;
        }
        int cond = !mod;
        z_row_base[i] = cond ? x_row_base[i / m] : shift_val;
    }
}
