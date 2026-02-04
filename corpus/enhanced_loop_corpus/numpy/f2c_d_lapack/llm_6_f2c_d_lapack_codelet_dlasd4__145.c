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
    doublereal base_val = d__[*n] + temp1;
    for (j = 1; j <= i__1; ++j) {
        work[j] = d__[j] + base_val;
        delta[j] = d__[j] - base_val;
    }
}
