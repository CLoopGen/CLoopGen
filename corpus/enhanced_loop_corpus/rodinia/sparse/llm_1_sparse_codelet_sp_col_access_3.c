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
if (n > 0) {
    for (j = 0; j < n; j += 2) {
        *start_row++ = -1;
        *start_idx++ = -1;
        if (j + 1 < n) {
            *start_row++ = -1;
            *start_idx++ = -1;
        }
    }
}
}
