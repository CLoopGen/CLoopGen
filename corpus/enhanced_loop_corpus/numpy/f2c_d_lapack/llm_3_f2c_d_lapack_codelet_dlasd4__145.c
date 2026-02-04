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
    // Variant 2: Consecutive forward access with unrolled loop (factor of 2)
    // Improves spatial locality and reduces loop overhead
    integer limit = i__1 - 1;
    for (j = 1; j <= limit; j += 2) {
        work[j]     = d__[j]     + d__[*n] + temp1;
        delta[j]   = d__[j]     - d__[*n] - temp1;
        work[j+1]   = d__[j+1]   + d__[*n] + temp1;
        delta[j+1] = d__[j+1]   - d__[*n] - temp1;
    }
    // Handle remaining element if i__1 is odd
    if (i__1 % 2 == 1) {
        work[i__1] = d__[i__1] + d__[*n] + temp1;
        delta[i__1] = d__[i__1] - d__[*n] - temp1;
    }
}
