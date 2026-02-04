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
    doublereal temp_d_i = d__[*i__] + eta;
    for (j = 1; j <= i__1; ++j) {
        work[j] = d__[j] + temp_d_i;
        delta[j] = d__[j] - temp_d_i;
    }
}
