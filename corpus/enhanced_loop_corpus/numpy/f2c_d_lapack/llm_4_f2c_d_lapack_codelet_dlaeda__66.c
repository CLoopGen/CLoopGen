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
    for (k = 1; k <= i__1; ++k) {
        if (k % 2 == 0) {
            z__[k] = 0.;
        } else {
            continue;
        }
    }
}
