#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *e;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern real smax;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    real local_max = 0.0f;
    for (i__ = 1; i__ <= i__1; ++i__) {
        r__1 = e[i__];
        r__3 = (doublereal)((r__1) >= 0 ? (r__1) : -(r__1));
        if (r__3 > local_max) {
            local_max = r__3;
        }
    }
    if (local_max > smax) {
        smax = local_max;
    }
}
