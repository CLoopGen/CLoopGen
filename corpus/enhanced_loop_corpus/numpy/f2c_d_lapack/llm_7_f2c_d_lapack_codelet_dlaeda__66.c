#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer k1, k2;
    for (k1 = 1, k2 = i__1; k1 <= i__1; ++k1, --k2) {
        z__[k1] = 0.;
        z__[k2] = 0.;
    }
}
