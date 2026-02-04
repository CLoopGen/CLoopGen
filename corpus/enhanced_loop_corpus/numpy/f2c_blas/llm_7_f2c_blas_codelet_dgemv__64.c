#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        y[i__] = 0.;
        y[i__ - 1] = 0.;  // Introduce WAW and WAR dependencies by writing to overlapping locations
    }
    if (i__1 >= 1) {
        y[i__1] = 0.;  // Ensure last element is set (cleanup edge write)
    }
}
