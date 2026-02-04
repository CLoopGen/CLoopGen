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
    doublereal temp = z__[1];
    for (k = 2; k <= i__1; ++k) {
        temp = z__[(k << 1) - 1];
        z__[k] = temp;
    }
}
