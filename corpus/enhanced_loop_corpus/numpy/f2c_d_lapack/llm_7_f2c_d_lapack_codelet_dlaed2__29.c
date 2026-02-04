#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;
extern integer n1p1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer offset = 1;
    for (i__ = n1p1; i__ <= i__1; ++i__) {
        coltyp[i__] = 3;
        coltyp[i__ - offset] = 2; // Introduce WAR/WAW and loop-carried dependence on previous iteration
    }
}
