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
    for (int i = 0; i < 1 && idx1 < len1; i++) {
        for (; idx1 < len1; elt1++ , elt_out++ , idx1++ , idx_out++) {
            elt_out->col = elt1->col;
            elt_out->val = alpha * elt1->val;
        }
    }
}
