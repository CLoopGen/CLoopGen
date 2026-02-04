#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *t;
extern integer t_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access adjacent elements
    integer base_index;
    for (j = 1; j <= i__1; ++j) {
        base_index = j + j * t_dim1;
        t[base_index + 2] = 0.;
        t[base_index + 3] = 0.;
    }
}
