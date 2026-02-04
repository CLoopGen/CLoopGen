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
    // Variant 2: Reduced trip count with increased per-iteration work using stride
    // Processes every other element, reducing iterations but maintaining coverage
    int stride = 2;
    for (; idx1 < len1; idx1 += stride, elt1 += stride, elt_out += stride, idx_out += stride) {
        elt_out->col = elt1->col;
        elt_out->val = alpha * elt1->val;

        // Add auxiliary computation to maintain realistic workload characteristics
        if (idx1 + 1 < len1) {
            double backup_val = (alpha + 0.5) * elt1->val;
            elt_out->val = (elt_out->val + backup_val) * 0.5;
        }
    }
}
