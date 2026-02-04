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
    // Variant 2: Strided memory access with increased stride (access every second element)
    // Simulates non-unit stride access, which may affect cache performance
    for (j = 1; j <= i__1; j += 2) {
        if (j + c_dim1 < (size_t)j * 2) { // Simple bounds check to avoid overflow
            c__[j + c_dim1] = t1 * c__[j + c_dim1];
        }
    }
}
