#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (j % 2 == 0) {
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            c__[i__ + j * c_dim1] = 0.;
        }
    }
}
}
