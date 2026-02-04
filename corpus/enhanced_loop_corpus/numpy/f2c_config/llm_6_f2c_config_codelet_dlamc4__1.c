#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer i__;
extern doublereal b1;
extern doublereal d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = d1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += b1;
    }
    d1 = temp;
}
