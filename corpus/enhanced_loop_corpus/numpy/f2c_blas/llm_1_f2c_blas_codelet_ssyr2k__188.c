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
    i__2 = j;
    if (i__2 >= 1) {
        i__ = 1;
        do {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
            ++i__;
        } while (i__ <= i__2);
    }
}
}
