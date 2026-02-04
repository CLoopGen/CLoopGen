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
    double prev_tmp = 0.0;
    for (idx = 0; idx < len; idx++, elts++) {
        if (elts->col >= lim)
            break;
        tmp = elts->val + prev_tmp;  // Introduce RAW dependency: current tmp depends on previous iteration
        sum += tmp * tmp;
        prev_tmp = elts->val;  // WAW: prev_tmp overwrites each iteration; WAR: write after read in next iteration
    }
}
