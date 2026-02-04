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
    int start = (z)->xstart_;
    int end = (z)->xend_;
    int offset = (z)->xstart_;
    int x_offset = (x)->xstart_;
    jas_seqent_t *z_row = (z)->rows_[0];
    jas_seqent_t *x_row = (x)->rows_[0];
    int mod_val = m;
    int shift_val = 13;

    for (i = start; i < end; i += 2) {
        int idx = i - offset;
        int neg_i = -i;
        int abs_mod = (i < 0) ? ((neg_i % mod_val) ? (mod_val - (neg_i % mod_val)) : 0) : (i % mod_val);
        int condition = !abs_mod;
        int div_idx = (i / mod_val) - x_offset;

        z_row[idx] = condition ? x_row[div_idx] : ((jpc_fix_t)(0 << shift_val));
        
        // Second iteration of unrolled loop
        if (i + 1 < end) {
            int i2 = i + 1;
            int idx2 = i2 - offset;
            int neg_i2 = -i2;
            int abs_mod2 = (i2 < 0) ? ((neg_i2 % mod_val) ? (mod_val - (neg_i2 % mod_val)) : 0) : (i2 % mod_val);
            int condition2 = !abs_mod2;
            int div_idx2 = (i2 / mod_val) - x_offset;

            z_row[idx2] = condition2 ? x_row[div_idx2] : ((jpc_fix_t)(0 << shift_val));
        }
    }
}
