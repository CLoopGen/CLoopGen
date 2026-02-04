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
for (i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        int idx = i * 10 + j;
        scratch[idx].nxt_row = scratch[idx].nxt_idx = -1;
    }
}
}
