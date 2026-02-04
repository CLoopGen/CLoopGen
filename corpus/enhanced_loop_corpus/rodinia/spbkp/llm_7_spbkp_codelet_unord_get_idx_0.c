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
    int found = 0;
    idx = 0;
    e = r->elt;
    for (; !found && idx < r->len; ) {
        found = (e->col == j);
        if (!found) {
            idx++;
            e++;
        }
    }
}
