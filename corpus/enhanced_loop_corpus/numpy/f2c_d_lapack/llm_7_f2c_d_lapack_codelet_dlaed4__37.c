#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal accum = 0.0;
    for (j = 1; j <= i__1; ++j) {
        accum += d__[j];
        delta[j] = accum - d__[*i__] - midpt;
    }
}
