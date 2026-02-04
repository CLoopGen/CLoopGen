#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern integer ip1;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer k;
for (j = 2; j <= i__1; j += 2) {
    work[j-1] = d__[j-1] + d__[ip1] + eta;
    delta[j-1] = d__[j-1] - d__[ip1] - eta;
    work[j] = d__[j] + d__[ip1] + eta;
    delta[j] = d__[j] - d__[ip1] - eta;
}
if (i__1 % 2 == 1) {
    work[i__1] = d__[i__1] + d__[ip1] + eta;
    delta[i__1] = d__[i__1] - d__[ip1] - eta;
}
}
