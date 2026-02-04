#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *beta;
extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        for (i__ = j; i__ <= *n; ++i__) {
            for (int k = 0; k < 1; ++k) {
                c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
            }
        }
    }
}
