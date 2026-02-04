#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *beta;
extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= *n; ++i__) {
    for (j = 1; j <= i__1 && j <= i__; ++j) {
        c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
    }
}
}
