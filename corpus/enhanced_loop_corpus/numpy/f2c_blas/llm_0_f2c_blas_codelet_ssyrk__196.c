#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *beta;
extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (int k = j; k <= i__1; ++k) {
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
        }
    }
}
}
