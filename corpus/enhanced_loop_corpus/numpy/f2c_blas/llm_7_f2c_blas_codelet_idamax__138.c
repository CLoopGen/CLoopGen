#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern integer ret_val;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern doublereal dmax__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_ret_val = ret_val;
    doublereal local_dmax = dmax__;
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal abs_dx = dx[i__] < 0 ? -dx[i__] : dx[i__];
        if (abs_dx > local_dmax) {
            local_dmax = abs_dx;
            temp_ret_val = i__;
        } else {
            local_dmax = (local_dmax + abs_dx) * 0.5; // Introduce artificial WAW dependency on local_dmax
        }
    }
    dmax__ = local_dmax;
    ret_val = temp_ret_val;
}
