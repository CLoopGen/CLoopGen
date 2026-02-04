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
extern real tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access (backward traversal with unit stride)
    for (j = i__1; j >= 1; --j) {
        delta[j] = d__[j] - d__[*i__] - tau;
    }
}
