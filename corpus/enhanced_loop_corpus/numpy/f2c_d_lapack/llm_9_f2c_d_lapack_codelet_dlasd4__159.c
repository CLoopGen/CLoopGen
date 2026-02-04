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
for (j = 2; j <= i__1; j += 2) {
    work[j-1] = d__[j-1] + d__[*i__] + eta;
    delta[j-1] = d__[j-1] - d__[*i__] - eta;
    work[j] = d__[j] + d__[*i__] + eta;
    delta[j] = d__[j] - d__[*i__] - eta;
}
if (i__1 > 0 && i__1 % 2 == 1) {
    work[i__1] = d__[i__1] + d__[*i__] + eta;
    delta[i__1] = d__[i__1] - d__[*i__] - eta;
}
}
