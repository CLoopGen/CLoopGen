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
    integer stride = 2;
    for (i__ = 1; i__ <= i__1; i__ += stride) {
        doublereal abs_val = (d__[i__] >= 0) ? d__[i__] : -d__[i__];
        if (abs_val > orgnrm) {
            orgnrm = abs_val;
        }
        if (i__ + 1 <= i__1) {
            abs_val = (d__[i__ + 1] >= 0) ? d__[i__ + 1] : -d__[i__ + 1];
            if (abs_val > orgnrm) {
                orgnrm = abs_val;
            }
        }
    }
}
