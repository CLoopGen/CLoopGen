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
    real local_smax = smax;
    integer base_ix = ix;
    for (i__ = 2; i__ <= i__1; ++i__) {
        integer offset = (i__ - 2) * (*incx);
        real abs_val = (r__1 = sx[base_ix + offset], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        if (abs_val > local_smax) {
            ret_val = i__;
            local_smax = abs_val;
        }
    }
    smax = local_smax;
    ix = base_ix + (i__1 - 1) * (*incx);
}
