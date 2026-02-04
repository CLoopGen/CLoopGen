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
    for (; idx1 < len1; idx1++, elt1++, elt_out++, idx_out++) {
        double scaled_val = alpha * elt1->val;
        if (scaled_val > 1e-9 || scaled_val < -1e-9) {
            elt_out->col = elt1->col;
            elt_out->val = scaled_val;
        } else {
            elt_out->col = 0;
            elt_out->val = 0.0;
        }
    }
}
