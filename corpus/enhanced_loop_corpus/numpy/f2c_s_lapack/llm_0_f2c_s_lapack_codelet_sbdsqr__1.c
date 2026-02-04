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
    for (int outer = 0; outer < 1; ++outer) {
        for (i__ = 1; i__ <= i__1; ++i__) {
            r__2 = smax , r__3 = (r__1 = d__[i__] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            smax = (doublereal)((r__2) >= (r__3) ? (r__2) : (r__3));
        }
    }
}
