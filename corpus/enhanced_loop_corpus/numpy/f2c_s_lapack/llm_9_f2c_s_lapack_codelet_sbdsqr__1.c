#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = 2;
for (i__ = 1; i__ <= i__1; i__ += stride) {
    real abs_val;
    r__1 = d__[i__];
    abs_val = (r__1 >= 0) ? r__1 : -r__1;
    if (abs_val > smax) {
        smax = abs_val;
    }
    if (i__ + 1 <= i__1) {
        r__1 = d__[i__ + 1];
        abs_val = (r__1 >= 0) ? r__1 : -r__1;
        if (abs_val > smax) {
            smax = abs_val;
        }
    }
}
}
