#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer i__1;
integer i__;
doublereal b2;
doublereal d2;

void init_vars() {
    // Estimate iteration count for ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 simple operations/sec -> ~1e7 per 0.01 sec
    // This loop is very simple: one add and increment per iteration
    i__1 = 10000000;  // 10 million iterations should take ~0.01 seconds

    i__ = 0;  // Will be set to 1 at start of loop
    b2 = 3.14159;
    d2 = 0.0;
}