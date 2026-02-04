#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access by flattening the index and writing to contiguous locations
    integer base_index = 1 + a_dim1 + 1; // initial offset corresponding to [1][1]
    integer stride = a_dim1 + 1;          // diagonal increment
    for (i__ = 0; i__ < i__1; ++i__) {
        a[base_index + i__ * stride] = *beta;
    }
}
