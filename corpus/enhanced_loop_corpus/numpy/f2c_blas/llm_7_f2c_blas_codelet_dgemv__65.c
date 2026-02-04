#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal beta_val = *beta;
    doublereal prev = y[1];
    y[1] = beta_val * y[1];
    for (i__ = 2; i__ <= i__1; ++i__) {
        doublereal current = y[i__];
        y[i__] = beta_val * current + prev;
        prev = current;
    }
}
