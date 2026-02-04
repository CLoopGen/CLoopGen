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
    for (k = 4; k <= i__1; k += 4) {
        z__[k - 3] = z__[((k - 3) << 2) - 3];
        z__[k - 2] = z__[((k - 2) << 2) - 3];
        z__[k - 1] = z__[((k - 1) << 2) - 3];
        z__[k]     = z__[(k << 2) - 3];
    }
}
