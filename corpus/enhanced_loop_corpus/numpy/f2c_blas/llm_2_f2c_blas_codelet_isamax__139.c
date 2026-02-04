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
    // Variant 1: Consecutive Memory Access (assume incx == 1, unroll by 2)
    integer stride = *incx;
    integer offset = ix - stride; // Adjust base index to allow consecutive indexing from sx[0]
    
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        real val1 = sx[offset + i__ - 1];
        real abs_val1 = (val1 >= 0) ? val1 : -val1;
        
        if (abs_val1 > smax) {
            ret_val = i__ - 1;
            smax = abs_val1;
        }
        
        if (i__ < i__1) {
            real val2 = sx[offset + i__];
            real abs_val2 = (val2 >= 0) ? val2 : -val2;
            
            if (abs_val2 > smax) {
                ret_val = i__;
                smax = abs_val2;
            }
        }
        ix += 2 * stride;
    }
    
    // Handle odd-sized tail if needed
    if ((i__1 - 1) % 2 != 0) {
        real val = sx[ix - *incx];
        real abs_val = (val >= 0) ? val : -val;
        if (abs_val > smax) {
            ret_val = i__1;
            smax = abs_val;
        }
    }
}
