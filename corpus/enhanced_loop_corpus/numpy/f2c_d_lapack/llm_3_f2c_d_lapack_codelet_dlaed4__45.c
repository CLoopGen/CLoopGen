#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with pointer arithmetic
    doublereal *z_ptr = &z__[i__1];
    doublereal *delta_ptr = &delta[i__1];
    integer length = *n - i__1 + 1;
    for (j = 0; j < length; ++j) {
        phi += z_ptr[j] * z_ptr[j] / delta_ptr[j];
    }
    // Adjust j to reflect original indexing (if used outside, though not required here)
    j = *n;
}
