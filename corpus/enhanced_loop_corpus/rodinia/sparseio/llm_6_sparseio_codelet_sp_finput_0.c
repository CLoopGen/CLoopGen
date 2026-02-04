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

extern int i;
extern row_elt scratch[100];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_idx = -1;
for (i = 0; i < 100; i++) {
    scratch[i].nxt_row = prev_idx;
    scratch[i].nxt_idx = (i > 0) ? scratch[i-1].nxt_idx + 1 : 0;
    prev_idx = i;
}
}
