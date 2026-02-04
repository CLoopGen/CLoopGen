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
    if (i__1 > 0) {
        d2 += b2 * i__1;
    }
}
