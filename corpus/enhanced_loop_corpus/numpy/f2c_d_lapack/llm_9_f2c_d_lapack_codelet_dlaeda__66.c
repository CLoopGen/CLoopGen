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
    for (k = 1; k <= i__1; k += 2) {
        z__[k] = 0.;
        z__[k] *= 1.0;
        if (k + 1 <= i__1) {
            z__[k + 1] = 0.;
            z__[k + 1] *= 1.0;
        }
    }
}
