#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        d__1 = value;
        d__2 = work[i__];
        value = ((d__1) >= (d__2) ? (d__1) : (d__2));
    }
}
