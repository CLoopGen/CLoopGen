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
extern jas_seq_t *y;
extern int i;
extern int j;
extern int k;
extern jas_seq_t *z;
extern jpc_fix_t s;
extern jpc_fix_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int xstart = (x)->xstart_;
int ystart = (y)->xstart_;
int zstart = (z)->xstart_;
int xend = (x)->xend_;
int yend = (y)->xend_;
int zend = (z)->xend_;
jas_seqent_t *x_data = (x)->rows_[0] - xstart;
jas_seqent_t *y_data = (y)->rows_[0] - ystart;
jas_seqent_t *z_data = (z)->rows_[0] - zstart;
for (i = zstart; i < zend; i++) {
    s = ((jpc_fix_t)((0) << (13)));
    int j_offset = (i >= xend - 1) ? i - xend + 1 : ystart;
    j_offset = (j_offset < ystart) ? ystart : j_offset;
    for (j = j_offset; j < yend && (i - j) < xend; j++) {
        k = i - j;
        v = (k >= xstart) ? x_data[k] : ((jpc_fix_t)(0));
        s = ((s) + (((jpc_fix_t)((((jpc_fix_big_t)(y_data[j])) * ((jpc_fix_big_t)(v))) >> (13)))));
    }
    z_data[i] = s;
}
}
