#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern integer ip1;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from high to low)
    for (j = i__1; j >= 1; --j) {
        work[j] = d__[j] + d__[ip1] + eta;
        delta[j] = d__[j] - d__[ip1] - eta;
    }
}
