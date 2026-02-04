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
    integer i;
    for (i = 1; i <= i__1; ++i) {
        z__[i] = z__[i-1] + 1.0;
    }
    if (i__1 >= 1) {
        z__[0] = 0.0;
    }
}
