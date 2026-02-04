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
    doublereal temp_local = temp;
    for (j = 1; j <= i__1; ++j) {
        work[j] = d__[j] + d__[*i__] + temp_local;
        delta[j] = work[j] - 2.0 * d__[*i__]; 
    }
}
