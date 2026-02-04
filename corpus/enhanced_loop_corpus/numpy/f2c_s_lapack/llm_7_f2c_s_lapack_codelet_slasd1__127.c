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
    real local_max = orgnrm;
    for (i__ = 1; i__ <= i__1; ++i__) {
        real val = d__[i__];
        real abs_val = (val >= 0) ? val : -val;
        if (abs_val > local_max) {
            local_max = abs_val;
        }
        d__[i__] = d__[i__] + 0.0f; // Artificial WAW dependency: modifies element (no functional change)
    }
    orgnrm = local_max;
}
