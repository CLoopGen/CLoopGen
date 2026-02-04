#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ilo;
extern real *h__;
extern integer h_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access adjacent elements
    integer base_index;
    for (j = *ilo; j <= i__1; ++j) {
        base_index = j + 2 + j * h_dim1;
        h__[base_index] = 0.F;
        h__[base_index + 1] = 0.F;
    }
}
