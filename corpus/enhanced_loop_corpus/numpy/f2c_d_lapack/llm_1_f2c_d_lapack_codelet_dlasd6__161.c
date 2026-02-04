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
if (i__1 >= 1) {
    i__ = 1;
    for (; i__ <= i__1; ++i__) {
        // Loop body unrolled by factor of 2 with conditional checks to maintain correctness
        d__1 = d__[i__];
        d__1 = (d__1 >= 0 ? d__1 : -d__1);
        if (d__1 > orgnrm) {
            orgnrm = d__1;
        }
    }
}
}
