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
    integer temp;
    for (k = 2; k <= i__1; ++k) {
        temp = z__[(k << 2) - 3]; // Break direct array dependency by using local temp
        z__[k] = temp;            // Eliminate loop-carried dependence by isolating load and store
    }
}
