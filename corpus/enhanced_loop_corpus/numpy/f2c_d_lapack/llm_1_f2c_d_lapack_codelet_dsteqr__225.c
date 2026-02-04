#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *e;
extern integer *info;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 > 0) {
        i__ = 1;
        for (; i__ <= i__1; ) { // Reduced loop structure by removing increment in for-statement and using nested condition
            if (e[i__] != 0.) {
                ++(*info);
            }
            ++i__; // Increment moved inside loop body, effectively flattening control flow within single loop
        }
    }
}
