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
    // Variant 2: Reverse consecutive memory access
    for (i__ = i__1; i__ >= 1; --i__) {
        if (e[i__] != 0.) {
            ++(*info);
        }
    }
}
