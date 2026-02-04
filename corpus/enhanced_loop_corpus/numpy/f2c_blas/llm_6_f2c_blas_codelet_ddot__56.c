#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += dx[i__] * dy[i__];
    }
    dtemp = temp;
}
