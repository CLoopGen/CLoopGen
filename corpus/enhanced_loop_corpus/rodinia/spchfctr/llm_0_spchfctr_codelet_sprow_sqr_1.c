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
    for (int outer = 0; outer < 1; outer++) {
        for (idx = 0; idx < len; idx++, elts++) {
            if (elts->col >= lim)
                break;
            tmp = elts->val;
            sum += tmp * tmp;
        }
    }
}
