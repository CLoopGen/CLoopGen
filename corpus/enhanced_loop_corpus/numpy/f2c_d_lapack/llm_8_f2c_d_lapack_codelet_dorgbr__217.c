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
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and reduced trip count by iterating every 2nd element.
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        a[i__ + a_dim1] = (doublereal)(i__ * i__) / 4.0;
        a[i__ + a_dim1 + 1] = (doublereal)(i__ * (i__ + 1)) / 4.0;
    }
}
