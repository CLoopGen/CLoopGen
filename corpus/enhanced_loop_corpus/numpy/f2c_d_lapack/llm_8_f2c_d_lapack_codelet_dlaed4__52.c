#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern integer ip1;
extern doublereal tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        delta[j] = d__[j] - d__[ip1] - tau * 2.0 + d__[j] * 0.5;
    }
}
