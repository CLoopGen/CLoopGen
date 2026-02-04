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
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1 * 2; ++j) {
        work[j] = d__[(j-1)%i__1+1] + d__[*i__] + temp;
        delta[j] = d__[(j-1)%i__1+1] - d__[*i__] - temp;
    }
}
