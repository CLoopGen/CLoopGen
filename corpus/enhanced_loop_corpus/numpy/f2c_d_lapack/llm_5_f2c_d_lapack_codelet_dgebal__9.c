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
    for (i__ = k; i__ <= i__1; ++i__) {
        scale[i__] = 1.;
        if (i__ == k + 5) {
            break;
        }
    }
}
