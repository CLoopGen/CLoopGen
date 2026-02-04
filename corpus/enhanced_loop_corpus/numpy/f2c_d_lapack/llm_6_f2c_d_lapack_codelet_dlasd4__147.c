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
    doublereal temp_delta;
    doublereal temp_work;
    for (j = 1; j <= i__1; ++j) {
        temp_delta = d__[j] - d__[*i__] - eta;
        temp_work = d__[j] + d__[*i__] + eta;
        delta[j] = temp_delta;
        work[j] = temp_work;
    }
}
