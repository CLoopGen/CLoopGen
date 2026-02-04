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
    doublereal temp_c = *c__;
    doublereal temp_s = *s;
    for (i__ = 1; i__ <= i__1; ++i__) {
        dtemp = temp_c * dx[i__] + temp_s * dy[i__];
        dy[i__] = temp_c * dy[i__] - temp_s * dx[i__];
        dx[i__] = dtemp;
    }
}
