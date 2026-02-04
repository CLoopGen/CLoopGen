#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal carry = 1.0;
    for (i__ = 1; i__ <= i__2; ++i__) {
        carry *= dx[i__];
        dx[i__] = *da * carry;
    }
}
