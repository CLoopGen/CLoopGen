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



void loop(){
    // Reverse iteration order to change loop-carried dependency direction (if any existed)
    // This alters data access pattern but maintains semantic equivalence assuming no external dependencies

    int_fast32_t start = (z)->xstart_;
    int_fast32_t end = (z)->xend_;
    jas_seqent_t** z_rows = (z)->rows_;
    jas_seqent_t** x_rows = (x)->rows_;
    int_fast32_t z_xstart = (z)->xstart_;
    int_fast32_t x_xstart = (x)->xstart_;
    int m_val = m;
    jpc_fix_t default_val = (jpc_fix_t)((0) << (13));

    // Loop runs backward — changes potential for loop-carried dependencies (none logically present, but access reordered)
    for (i = end - 1; i >= start; i--) {
        int adjusted_i = i - z_xstart;
        int mod_op = (i < 0) ? ((-i) % m_val ? m_val - ((-i) % m_val) : 0) : (i % m_val);
        jas_seqent_t value = mod_op ? default_val : x_rows[0][(i / m_val) - x_xstart];
        z_rows[0][adjusted_i] = value;
    }

    // Note: 'i' will be left modified after loop (equals start-1), but original code also leaves i in modified state.
}
