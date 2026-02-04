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
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (j = i__1; j >= 1; j -= 2) {
        delta[j] = d__[j] - d__[*i__] - tau;
    }
    // Handle remaining element if i__1 is odd
    if (i__1 % 2 == 0 && i__1 >= 2) {
        delta[2] = d__[2] - d__[*i__] - tau;
    }
}
