#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = (j % 3 == 0) ? j : j + 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (i__ % 2 == 0) {
            c__[i__ + j * c_dim1] = -1.0;
        } else {
            c__[i__ + j * c_dim1] = 1.0;
        }
    }
}
}
