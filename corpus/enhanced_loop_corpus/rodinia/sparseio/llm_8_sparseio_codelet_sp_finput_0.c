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
int j;
for (i = 0; i < 200; i += 2) {
    for (j = 0; j < 2; j++) {
        int idx = i + j;
        if (idx < 100) {
            scratch[idx].nxt_row = -1;
            scratch[idx].nxt_idx = -1;
        }
    }
}
}
