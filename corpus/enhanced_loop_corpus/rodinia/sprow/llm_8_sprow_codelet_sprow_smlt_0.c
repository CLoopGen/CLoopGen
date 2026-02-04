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
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and unrolled loop behavior (simulated by processing two elements per iteration)
    int step = 2;
    for (; idx1 < len1 - 1; elt1 += 2, elt_out += 2, idx1 += 2, idx_out += 2) {
        // First element
        elt_out[0].col = elt1[0].col;
        elt_out[0].val = alpha * elt1[0].val + alpha - elt1[0].val;

        // Second element
        elt_out[1].col = elt1[1].col;
        elt_out[1].val = alpha * elt1[1].val + alpha - elt1[1].val;

        // Additional computation to increase intensity
        double temp = elt_out[0].val * elt_out[1].val;
        elt_out[0].val += temp * 0.1;
        elt_out[1].val -= temp * 0.1;
    }
    // Handle remaining element if any
    if (idx1 < len1) {
        elt_out->col = elt1->col;
        elt_out->val = alpha * elt1->val;
        idx1++; idx_out++;
    }
}
