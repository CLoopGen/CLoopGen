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
    // Variant 1: Strided Memory Access (access every 2nd element in a strided pattern)
    for (j = 1; j <= i__1; j += 2) {
        if (j <= i__1) {
            delta[j] = d__[j] - d__[*i__] - eta;
            work[j] = d__[j] + d__[*i__] + eta;
        }
    }
    // Handle remaining element if i__1 is odd
    if (i__1 % 2 == 0 && i__1 >= 1) {
        delta[i__1] = d__[i__1] - d__[*i__] - eta;
        work[i__1] = d__[i__1] + d__[*i__] + eta;
    }
}
