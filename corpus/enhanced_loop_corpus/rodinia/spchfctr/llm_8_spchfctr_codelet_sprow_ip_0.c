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
    int i = 0;
    for (; i < len1 && i < len2; i++) {
        tmp = elts1[i].col - elts2[i].col;
        if (tmp == 0) {
            sum += elts1[i].val * elts2[i].val;
            if (elts1[i].col >= lim || elts2[i].col >= lim)
                break;
        }
    }
}
