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
    for (integer outer = 1; outer <= 1; ++outer) {
        for (i__ = 2; i__ <= i__1; ++i__) {
            doublereal temp_abs = dx[ix];
            temp_abs = temp_abs >= 0 ? temp_abs : -temp_abs;
            if (temp_abs <= dmax__) {
                goto L5;
            }
            ret_val = i__;
            dmax__ = temp_abs;
          L5:
            ix += *incx;
        }
    }
}
