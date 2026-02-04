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
    integer stride = 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal temp_abs = dx[i__];
        temp_abs = temp_abs < 0 ? -temp_abs : temp_abs;
        if (temp_abs <= dmax__) {
            continue;
        }
        ret_val = i__;
        dmax__ = temp_abs;
        i__ += (stride - 1);
        stride = (stride < 8) ? stride * 2 : 8;
    }
}
