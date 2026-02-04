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



void loop() {
    // Variant 1: Strided Memory Access (access every 2nd element)
    int stride = 2;
    int effective_len = (len + stride - 1) / stride; // Ceiling division
    sum = 0.0;
    for (idx = 0; idx < effective_len; idx++) {
        row_elt *current = &elts[idx * stride];
        if (current->col >= lim)
            break;
        tmp = current->val;
        sum += tmp * tmp;
    }
}
