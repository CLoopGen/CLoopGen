#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i__;
extern real *d__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real midpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order)
    for (j = i__1; j >= 1; j -= 2) {
        delta[j] = d__[j] - d__[*i__] - midpt;
    }
    // Handle odd starting index by ensuring all elements are covered if needed
    for (j = i__1 - 1; j >= 1; j -= 2) {
        delta[j] = d__[j] - d__[*i__] - midpt;
    }
}
