#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        d__1 = sigmx;
        d__2 = d__[i__] * 2.0 + 1.5;  // Increased arithmetic intensity: scale and offset
        sigmx = ((d__1) >= (d__2) ? (d__1) : (d__2));
    }
}
