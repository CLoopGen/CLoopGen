#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= i__1; j += 2) {
        real temp1 = d__[j-1] + d__[*i__] + eta;
        real temp2 = d__[j]   + d__[*i__] + eta;
        work[j-1] = temp1;
        work[j]   = temp2;
        delta[j-1] = d__[j-1] - d__[*i__] - eta;
        delta[j]   = d__[j]   - d__[*i__] - eta;
    }
    if (i__1 > 0 && i__1 % 2 == 1) {
        work[i__1] = d__[i__1] + d__[*i__] + eta;
        delta[i__1] = d__[i__1] - d__[*i__] - eta;
    }
}
