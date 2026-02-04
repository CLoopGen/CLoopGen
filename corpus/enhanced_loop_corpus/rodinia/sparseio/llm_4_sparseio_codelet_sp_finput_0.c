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
for (i = 0; i < 100; i++) {
    if (i % 2 == 0) {
        scratch[i].nxt_row = -1;
        scratch[i].nxt_idx = -1;
    } else {
        scratch[i].nxt_row = -2;
        scratch[i].nxt_idx = -2;
    }
}
}
