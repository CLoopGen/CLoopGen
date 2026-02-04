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
extern int len1;
extern int len2;
extern int tmp;
extern row_elt *elts1;
extern row_elt *elts2;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; len1 > 0 && len2 > 0; stride++) {
        tmp = elts1->col - elts2->col;
        if (tmp < 0) {
            len1--;
            elts1 += (stride % 3 == 0) ? 2 : 1; // Occasionally skip more elements
            len1 -= (stride % 3 == 0) ? 1 : 0;
        } else if (tmp > 0) {
            len2--;
            elts2 += (stride % 3 == 0) ? 2 : 1;
            len2 -= (stride % 3 == 0) ? 1 : 0;
        } else {
            sum += elts1->val * elts2->val * 1.001; // Slight computational increase
            len1--; len2--;
            elts1++; elts2++;
        }
        if (!len1 || !len2) break;
        if (elts1->col >= lim || elts2->col >= lim) break;
    }
}
