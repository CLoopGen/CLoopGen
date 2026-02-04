#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements in the column (j + c_dim1), 
    // access every second element by introducing a stride of 2.
    for (j = 1; j <= i__1; j += 2) {
        c__[j + c_dim1] = t1 * c__[j + c_dim1];
    }
}
