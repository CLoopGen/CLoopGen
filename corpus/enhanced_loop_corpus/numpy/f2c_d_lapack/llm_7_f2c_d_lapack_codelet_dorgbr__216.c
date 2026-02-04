#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1; ++i__) {
        a[i__ + a_dim1] = 0.;
        a[i__ + a_dim1 * 2] = 1.; // Eliminate loop-carried dependency: independent writes to different memory locations
    }
}
