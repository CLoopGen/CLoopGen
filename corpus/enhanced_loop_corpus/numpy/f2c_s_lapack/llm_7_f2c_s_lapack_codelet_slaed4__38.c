#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real acc = psi;
    for (j = 1; j <= i__1; ++j) {
        acc = acc + z__[j] * z__[j] / delta[j];
        psi = acc; // WAW dependency introduced: psi is updated every iteration (redundant but creates loop-carried WAW)
    }
}
