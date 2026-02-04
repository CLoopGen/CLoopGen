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
    int *row_ptr = start_row;
    int *idx_ptr = start_idx;
    int i;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            row_ptr[i] = -1;
            idx_ptr[i] = -1;
            row_ptr[i + 1] = -1;
            idx_ptr[i + 1] = -1;
        } else {
            row_ptr[i] = -1;
            idx_ptr[i] = -1;
        }
    }
    start_row += n;
    start_idx += n;
}
