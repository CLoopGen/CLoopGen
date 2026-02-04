#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int n;
extern int *start_row;
extern int *start_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_start_row_val = -1;
    for (j = 0; j < n; j++) {
        int current = *start_row;
        *start_idx++ = prev_start_row_val;
        *start_row++ = -1;
        prev_start_row_val = current;
    }
}
