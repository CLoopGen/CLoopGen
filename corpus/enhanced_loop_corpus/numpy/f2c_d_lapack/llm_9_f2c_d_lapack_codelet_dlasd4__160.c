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
for (j = 2; j <= i__1; j += 2) {
    work[j-1] = d__[j-1] + d__[ip1] + eta;
    delta[j-1] = d__[j-1] - d__[ip1] - eta;
    work[j] = d__[j] + d__[ip1] + eta;
    delta[j] = d__[j] - d__[ip1] - eta;
}
}
