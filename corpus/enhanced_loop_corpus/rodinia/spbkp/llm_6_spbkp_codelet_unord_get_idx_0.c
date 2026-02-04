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

typedef struct SPROW {
    int len;
    int maxlen;
    int diag;
    row_elt *elt;
} SPROW;

extern SPROW *r;
extern int j;
extern int idx;
extern row_elt *e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_idx;
    row_elt *local_e = r->elt;
    for (local_idx = 0; local_idx < r->len; local_idx++) {
        if (local_e[local_idx].col == j) {
            idx = local_idx;
            e = &local_e[local_idx];
            break;
        }
    }
}
