#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *d__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real temp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1) {
        j = 1;
        work[j] = d__[j] + d__[*n] + temp1;
        delta[j] = d__[j] - d__[*n] - temp1;
    }
    for (j = 2; j <= i__1; ++j) {
        work[j] = d__[j] + d__[*n] + temp1;
        delta[j] = d__[j] - d__[*n] - temp1;
    }
}
