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

int i;
row_elt scratch[100];

void init_vars() {
    for (int idx = 0; idx < 100; idx++) {
        scratch[idx].col = 0;
        scratch[idx].nxt_row = 0;
        scratch[idx].nxt_idx = 0;
        scratch[idx].val = 0.0;
    }
    i = 0;
}