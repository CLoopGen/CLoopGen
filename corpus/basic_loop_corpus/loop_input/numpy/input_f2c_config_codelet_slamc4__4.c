#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer i__1;
integer i__;
real b2;
real d2;

void init_vars() {
    // Estimate iteration count to achieve ~0.01 seconds
    // Based on typical modern CPU speed and simple loop overhead
    // The loop is very simple: one floating point addition per iteration.
    // Assume about 1e9 operations per second -> 1e7 operations for 0.01 sec.

    i__1 = 10000000;  // 10 million iterations should take ~0.01 seconds
    i__ = 1;
    b2 = 1.5f;
    d2 = 0.0f;
}