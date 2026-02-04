#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *scale;
extern integer i__1;
extern integer i__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = k; i__ <= i__1; i__ += 2) {
        scale[i__] = 1.0;
        if (i__ + 1 <= i__1) {
            scale[i__ + 1] = 1.0;
        }
    }
}
