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
    if (l <= i__1) {
        d__1 = e[l];
        for (i__ = l + 1; i__ <= i__1; ++i__) {
            e[i__ - 1] = d__1 * d__1;
            d__1 = e[i__];
        }
        e[i__1] = d__1 * d__1;
    }
}
