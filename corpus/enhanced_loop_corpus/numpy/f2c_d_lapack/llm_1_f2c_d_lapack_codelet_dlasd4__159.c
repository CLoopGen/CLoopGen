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
if (i__1 >= 1) {
    work[1] = d__[1] + d__[*i__] + eta;
    delta[1] = d__[1] - d__[*i__] - eta;
}
for (j = 2; j <= i__1; ++j) {
    work[j] = d__[j] + d__[*i__] + eta;
    delta[j] = d__[j] - d__[*i__] - eta;
}
}
