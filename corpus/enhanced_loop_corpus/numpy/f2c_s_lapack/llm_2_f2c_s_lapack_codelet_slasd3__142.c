#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *u;
extern real *u2;
extern integer u_dim1;
extern integer u2_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every second element in a strided manner
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        u[i__ + u_dim1] = -u2[i__ + u2_dim1];
    }
}
