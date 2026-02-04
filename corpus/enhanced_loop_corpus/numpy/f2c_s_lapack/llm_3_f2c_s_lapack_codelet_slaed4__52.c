#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *delta;
extern integer i__1;
extern integer j;
extern integer ip1;
extern real tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from high to low index)
    for (j = i__1; j >= 1; --j) {
        delta[j] = d__[j] - d__[ip1] - tau;
    }
}
