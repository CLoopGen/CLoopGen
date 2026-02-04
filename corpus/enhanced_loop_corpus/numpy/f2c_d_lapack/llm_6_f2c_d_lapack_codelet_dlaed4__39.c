#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp = d__[*i__] + tau;
    for (j = 1; j <= i__1; ++j) {
        delta[j] = d__[j] - temp;
    }
}
