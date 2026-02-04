#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern integer ip1;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_work, temp_delta;
    for (j = 1; j <= i__1; ++j) {
        // Eliminate loop-carried dependencies by using temporaries and updating after computation
        temp_work = d__[j] + d__[ip1] + eta;
        temp_delta = d__[j] - d__[ip1] - eta;
        work[j] = temp_work;
        delta[j] = temp_delta;
    }
}
