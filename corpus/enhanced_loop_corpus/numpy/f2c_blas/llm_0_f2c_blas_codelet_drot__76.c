#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern doublereal *c__;
extern doublereal *s;
extern integer i__1;
extern integer i__;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal temp_c = *c__;
        doublereal temp_s = *s;
        doublereal dx_val = dx[i__];
        doublereal dy_val = dy[i__];
        dtemp = temp_c * dx_val + temp_s * dy_val;
        dy[i__] = temp_c * dy_val - temp_s * dx_val;
        dx[i__] = dtemp;
    }
}
