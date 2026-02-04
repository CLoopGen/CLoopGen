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
extern integer i__;
extern real orgnrm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_max = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        r__1 = d__[i__];
        real abs_val = (r__1) >= 0 ? (r__1) : -(r__1);
        if (abs_val > local_max) {
            local_max = abs_val;
        }
    }
    if (local_max > orgnrm) {
        orgnrm = local_max;
    }
}
