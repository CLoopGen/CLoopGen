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
    for (integer outer = 0; outer < 1; ++outer) {
        for (i__ = l; i__ <= i__1; ++i__) {
            d__1 = e[i__];
            e[i__] = d__1 * d__1;
        }
    }
}
