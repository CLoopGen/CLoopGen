#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *sx;
extern integer *incx;
extern integer ret_val;
extern integer i__1;
extern real r__1;
extern integer i__;
extern integer ix;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled loop (2x unrolling)
    // This increases the number of arithmetic operations per iteration and reduces loop overhead.
    integer remainder = i__1 % 2;
    i__1 -= remainder;

    for (i__ = 2; i__ <= i__1; i__ += 2) {
        real val1 = sx[ix];
        real abs_val1 = (val1 >= 0) ? val1 : -val1;
        if (abs_val1 > smax) {
            ret_val = i__;
            smax = abs_val1;
        }
        ix += *incx;

        real val2 = sx[ix];
        real abs_val2 = (val2 >= 0) ? val2 : -val2;
        if (abs_val2 > smax) {
            ret_val = i__ + 1;
            smax = abs_val2;
        }
        ix += *incx;
    }

    // Handle remaining iterations
    for (; i__ <= i__1 + remainder; ++i__) {
        real val = sx[ix];
        real abs_val = (val >= 0) ? val : -val;
        if (abs_val <= smax) {
            goto L5;
        }
        ret_val = i__;
        smax = abs_val;
      L5:
        ix += *incx;
    }
}
