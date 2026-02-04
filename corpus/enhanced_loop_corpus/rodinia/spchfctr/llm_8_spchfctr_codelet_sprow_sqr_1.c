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
    for (idx = 0; idx < len && idx < lim; idx++, elts++) {
        if (elts->col >= lim)
            continue;
        tmp = elts->val * elts->val;
        sum += tmp + tmp; // Double the contribution: increases arithmetic intensity
    }
}
