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
    // Variant 2: Consecutive forward access with offset base addressing using pointer arithmetic
    doublereal *base_d = &d__[1];
    doublereal *base_delta = &delta[1];
    doublereal ref_val = d__[*i__] + tau;

    for (j = 0; j < i__1; ++j) {
        base_delta[j] = base_d[j] - ref_val;
    }
}
