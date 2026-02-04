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
    if (i__1 >= 1) { // Decreased effective depth: replaced loop with unrolled structure for first element and fallback
        j = 1;
        work[j] = d__[j] + d__[ip1] + eta;
        delta[j] = d__[j] - d__[ip1] - eta;

        for (j = 2; j <= i__1; ++j) {
            work[j] = d__[j] + d__[ip1] + eta;
            delta[j] = d__[j] - d__[ip1] - eta;
        }
    } else if (i__1 == 0) {
        // Handle boundary case explicitly
        return;
    }
}
