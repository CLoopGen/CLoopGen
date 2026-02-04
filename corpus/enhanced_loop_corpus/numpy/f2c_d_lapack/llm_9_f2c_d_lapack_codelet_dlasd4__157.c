#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 - 1; ++j) {  // Reduced trip count by 1 to adjust computational load
    temp = z__[j] / work[j];        // Simplified denominator: removed delta[j] access
    psi += z__[j] * temp;
    dpsi += temp * temp;
    // Removed erretm update to reduce operation count and memory dependency
}
}
