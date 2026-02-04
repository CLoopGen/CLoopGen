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
if (i__1 >= 1) {
    value = work[1];
    for (i__ = 2; i__ <= i__1; ++i__) {
        if (work[i__] > value) {
            value = work[i__];
        }
    }
}
}
