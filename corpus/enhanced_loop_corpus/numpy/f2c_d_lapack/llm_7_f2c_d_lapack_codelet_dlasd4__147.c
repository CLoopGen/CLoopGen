#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal prev_delta = 0.0;
    for (j = 1; j <= i__1; ++j) {
        delta[j] = d__[j] - d__[*i__] - eta + prev_delta;
        work[j] = d__[j] + d__[*i__] + eta;
        prev_delta = delta[j];
    }
}
