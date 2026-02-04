#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        if (j != i__) {
            c__[i__ + j * c_dim1] = 0.F;
            c__[i__ + (j+1) * c_dim1] = 0.F;
        } else {
            c__[i__ + j * c_dim1] = 1.F;
        }
    }
}
}
