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
for (i = ((z)->xstart_); i < ((z)->xend_); i++) {
    jas_seqent_t value;
    int mod_val;
    if (i >= 0) {
        mod_val = i % m;
    } else {
        int neg_mod = (-i) % m;
        mod_val = neg_mod ? (m - neg_mod) : 0;
    }
    if (mod_val == 0) {
        value = (x)->rows_[0][(i / m) - (x)->xstart_];
    } else {
        value = (jpc_fix_t)(0 << 13);
    }
    (z)->rows_[0][(i) - (z)->xstart_] = value;
}
}
