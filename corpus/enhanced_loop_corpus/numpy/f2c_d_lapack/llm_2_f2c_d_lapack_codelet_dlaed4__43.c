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
extern doublereal midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order)
    for (j = i__1; j >= 1; j -= 2) {
        delta[j] = d__[j] - d__[*i__] - midpt;
    }
    // Handle the odd index if i__1 is odd
    if (i__1 % 2 == 0 && i__1 >= 2) {
        delta[1] = d__[1] - d__[*i__] - midpt;
    }
}
