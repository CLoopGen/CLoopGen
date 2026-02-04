#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = 0.0;
    for (i__ = l; i__ <= i__1; ++i__) {
        temp = e[i__];
        e[i__] = temp * temp;
    }
}
