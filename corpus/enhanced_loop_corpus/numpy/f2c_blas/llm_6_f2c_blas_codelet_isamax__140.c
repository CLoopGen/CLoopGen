#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *sx;
extern integer ret_val;
extern integer i__1;
extern real r__1;
extern integer i__;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_abs;
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp_abs = (r__1 = sx[i__], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        if (temp_abs <= smax) {
            continue;
        }
        ret_val = i__;
        smax = temp_abs;
    }
}
