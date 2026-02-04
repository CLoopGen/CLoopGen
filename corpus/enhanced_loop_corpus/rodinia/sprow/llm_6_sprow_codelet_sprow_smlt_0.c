#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct row_elt {
    int col;
    int nxt_row;
    int nxt_idx;
    double val;
} row_elt;

extern double alpha;
extern int idx1;
extern int idx_out;
extern int len1;
extern row_elt *elt1;
extern row_elt *elt_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double alpha_local = alpha;
    for (; idx1 < len1; idx1++, idx_out++) {
        elt_out->col = elt1->col;
        elt_out->nxt_row = elt1->nxt_row;
        elt_out->nxt_idx = elt1->nxt_idx;
        elt_out->val = alpha_local * elt1->val;
        elt1++;
        elt_out++;
    }
}
