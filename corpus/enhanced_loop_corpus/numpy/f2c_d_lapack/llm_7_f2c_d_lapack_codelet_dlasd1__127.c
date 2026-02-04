#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern doublereal orgnrm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_max = 0.0;
    integer stride = 2;
    for (i__ = 1; i__ <= i__1; i__ += stride) {
        doublereal abs_val_current = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        local_max = (abs_val_current > local_max) ? abs_val_current : local_max;
        if (i__ + 1 <= i__1) {
            doublereal abs_val_next = (d__1 = d__[i__ + 1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            local_max = (abs_val_next > local_max) ? abs_val_next : local_max;
        }
    }
    if (local_max > orgnrm) {
        orgnrm = local_max;
    }
}
