#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern doublereal d__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        d__1 = work[i__];
        work[i__] = d__1 * d__1;
    }
}
