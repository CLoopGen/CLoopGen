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
    // Variant 2: Reverse Order Consecutive Access (iterate from high to low)
    for (i__ = i__1; i__ >= 1; --i__) {
        u[i__ + u_dim1] = -u2[i__ + u2_dim1];
    }
}
