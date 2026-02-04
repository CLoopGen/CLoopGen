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
    jas_seqent_t* z_row = (z)->rows_[0] - (z)->xstart_;
    jas_seqent_t* x_row = (x)->rows_[0] - (x)->xstart_;
    int m_local = m;
    int_fast32_t start = (z)->xstart_;
    int_fast32_t end = (z)->xend_;
    jpc_fix_t zero_shifted = (jpc_fix_t)((0) << (13));

    for (i = start; i < end; i++) {
        int index = i - start;
        int mod_val = (i < 0) ? ((-i) % m_local ? m_local - ((-i) % m_local) : 0) : (i % m_local);
        int cond = !mod_val;
        int src_index = (i / m_local) - (x)->xstart_;

        // Introduce temporary variable to break direct WAW and RAW dependencies across iterations
        jas_seqent_t temp_val = cond ? x_row[src_index] : zero_shifted;
        z_row[i] = temp_val;
    }
}
