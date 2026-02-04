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

extern int lim;
extern row_elt *elts;
extern int idx;
extern int len;
extern double sum;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0;
    for (idx = 0; idx < len && elts->nxt_row < lim; idx += 2, elts += 2) {
        if (idx + 1 >= len) break;
        // Process two elements per iteration to increase computational density
        double val1 = elts->val;
        double val2 = (elts+1)->val;
        sum += val1 * val1 + val2 * val2;
    }
}
