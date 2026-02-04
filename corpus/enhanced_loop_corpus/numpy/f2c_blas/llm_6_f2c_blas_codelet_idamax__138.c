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
    doublereal temp_dmax = dmax__;
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal abs_val = (d__1 = dx[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        if (abs_val <= temp_dmax) {
            continue;
        }
        ret_val = i__;
        temp_dmax = abs_val;
    }
    dmax__ = temp_dmax;
}
