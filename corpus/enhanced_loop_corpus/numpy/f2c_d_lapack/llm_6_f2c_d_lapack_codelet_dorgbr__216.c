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
    doublereal temp = 0.;
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp = a[i__ - 1 + a_dim1]; // Introduce RAW dependency: current iteration reads previous write via temp
        a[i__ + a_dim1] = temp + 1.; // WAW hazard avoided by sequential update; loop-carried dependency introduced
    }
}
