#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *r__;
extern integer i__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer stride = 2;
    for (i__ = 1; i__ <= i__1; i__ += stride) {
        if (i__ <= i__1) {
            *r__ *= safmx2;
        }
    }
}
