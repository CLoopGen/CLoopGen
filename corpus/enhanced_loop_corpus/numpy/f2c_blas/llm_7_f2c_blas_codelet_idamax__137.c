#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer *incx;
extern integer ret_val;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern integer ix;
extern doublereal dmax__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer local_ix = ix;
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal abs_val = (d__1 = dx[local_ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
        if (abs_val <= dmax__) {
            local_ix += *incx;
            continue;
        }
        ret_val = i__;
        dmax__ = abs_val;
        local_ix += *incx;
    }
    ix = local_ix;
}
