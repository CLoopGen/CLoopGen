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



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    real abs_val = e[i__];
    if (abs_val < 0.0f) {
        abs_val = -abs_val;
    }
    if (abs_val > smax) {
        smax = abs_val;
    }
}
}
