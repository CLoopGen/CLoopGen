#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal temp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1) { // Reduce effective loop structure to a single-level conditional with no loop (depth decreased)
        j = 1;
        work[j] = d__[j] + d__[*n] + temp1;
        delta[j] = d__[j] - d__[*n] - temp1;
    }
}
