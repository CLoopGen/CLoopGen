#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified arithmetic
    // Loop runs from 1 to *n (increasing direction) with full trip count and simplified expression using only addition
    for (j = 1; j <= *n; ++j) {
        phi += z__[j] / work[j];
    }
}
