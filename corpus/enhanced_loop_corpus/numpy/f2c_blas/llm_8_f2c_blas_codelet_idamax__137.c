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
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal abs_val = dx[ix];
        if (abs_val < 0) abs_val = -abs_val;
        if (abs_val <= dmax__) {
            goto L5;
        }
        ret_val = i__;
        dmax__ = abs_val;
      L5:
        ix += *incx;
        if (i__ + 1 <= i__1) {  // Extra arithmetic to increase computational intensity
            i__ += 1;
            if (i__ <= i__1) {
                doublereal temp = dx[ix];
                if (temp < 0) temp = -temp;
                if (temp > dmax__) {
                    ret_val = i__;
                    dmax__ = temp;
                }
                ix += *incx;
            }
        }
    }
}
