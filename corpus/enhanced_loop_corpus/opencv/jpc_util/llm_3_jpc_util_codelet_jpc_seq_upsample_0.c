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
    // Variant 2: Strided access by unrolling the loop with a stride of 2 to simulate non-unit stride pattern
    // This variant processes elements in a strided manner, simulating optimization for cache or vectorization
    jas_seqent_t **z_rows = (z)->rows_;
    jas_seqent_t **x_rows = (x)->rows_;
    int_fast32_t start = (z)->xstart_;
    int_fast32_t end = (z)->xend_;
    int_fast32_t xstart = (x)->xstart_;
    jpc_fix_t default_val = (jpc_fix_t)((0) << (13));
    int stride = 2;

    // Handle odd start if needed, but keep loop logic clean
    for (i = start; i < end; i += stride) {
        // First element in stride
        int idx1 = i;
        int mod1 = (idx1 < 0) ? (((-idx1) % m) ? (m - ((-idx1) % m)) : 0) : (idx1 % m);
        z_rows[0][idx1 - (z)->xstart_] = !mod1 ? x_rows[0][(idx1 / m) - xstart] : default_val;

        // Second element in stride
        int idx2 = i + 1;
        if (idx2 >= end) break;
        int mod2 = (idx2 < 0) ? (((-idx2) % m) ? (m - ((-idx2) % m)) : 0) : (idx2 % m);
        z_rows[0][idx2 - (z)->xstart_] = !mod2 ? x_rows[0][(idx2 / m) - xstart] : default_val;
    }

    // Cleanup for odd-sized range if stride leaves a trailing element
    if ((end - start) % 2 == 1) {
        i = end - 1;
        int mod = (i < 0) ? (((-i) % m) ? (m - ((-i) % m)) : 0) : (i % m);
        (z)->rows_[0][i - (z)->xstart_] = !mod ? (x)->rows_[0][(i / m) - (x)->xstart_] : default_val;
    }
}
