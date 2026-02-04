#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *work;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count and unrolled loop to decrease total iterations but increase per-iteration work
    integer step = 2;
    for (i__ = 1; i__ <= i__1 - 1; i__ += step) {
        // Unroll two iterations into one
        r__1 = value; r__2 = work[i__];
        value = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
        
        r__1 = value; r__2 = work[i__ + 1];
        value = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
    // Handle remaining element if i__1 is odd
    if (i__ <= i__1) {
        r__1 = value; r__2 = work[i__];
        value = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
}
