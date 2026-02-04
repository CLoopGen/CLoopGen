#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array index into a sequential pattern
    // Assuming c__ is a 2D array stored in column-major order and c_dim1 is the leading dimension
    // We modify the access to traverse consecutive elements in memory by adjusting the base pointer
    real *base = &c__[c_dim1]; // Point to the start of the relevant column
    for (j = 1; j <= i__1; ++j) {
        base[j] = t1 * base[j];
    }
}
