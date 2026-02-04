#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer i__;
extern doublereal b2;
extern doublereal d2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (b2 > 0.0) {
            d2 += b2;
        }
    }
}
