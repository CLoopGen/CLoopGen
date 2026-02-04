#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1 * 2; ++i__) {
        work[i__ % (i__1 + 1 == 0 ? 1 : i__1 + 1)] = (doublereal)(i__ & 1) ? 0. : 1.;
    }
}
