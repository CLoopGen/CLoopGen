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
    doublereal temp = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += b2;
    }
    d2 += temp;
}
