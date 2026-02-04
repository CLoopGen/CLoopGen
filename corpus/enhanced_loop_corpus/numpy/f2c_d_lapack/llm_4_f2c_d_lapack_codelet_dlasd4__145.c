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
    for (j = 1; j <= i__1; ++j) {
        if (d__[j] >= d__[*n]) {
            work[j] = d__[j] + d__[*n] + temp1;
            delta[j] = d__[j] - d__[*n] - temp1;
        } else {
            work[j] = d__[j] + temp1;
            delta[j] = d__[j] - temp1;
        }
    }
}
