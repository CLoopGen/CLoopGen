#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *u;
extern doublereal *u2;
extern integer u_dim1;
extern integer u2_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        u[i__ + u_dim1] = -u2[i__ + u2_dim1] * 2.0 + 1.5;
    }
}
