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
    // Variant 2: Strided memory access (step of 2) with forward traversal
    for (j = 1; j <= i__1; j += 2) {
        delta[j] = d__[j] - d__[*i__] - midpt;
    }
    // Handle odd-sized arrays by processing last element if i__1 is even
    if (i__1 % 2 == 0) {
        delta[i__1] = d__[i__1] - d__[*i__] - midpt;
    }
}
