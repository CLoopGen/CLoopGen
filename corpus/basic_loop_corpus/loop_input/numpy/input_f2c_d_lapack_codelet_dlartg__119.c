#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *r__;
integer i__1;
integer i__;
doublereal safmn2;

void init_vars() {
    // Allocate and initialize r__ as a pointer to a single double value
    r__ = (doublereal*)malloc(sizeof(doublereal));
    if (!r__) exit(1);
    *r__ = 1.0;

    // Set safmn2 to a reasonable scaling factor (e.g., 0.5)
    safmn2 = 0.5;

    // Estimate iteration count for ~0.01s runtime
    // On modern CPUs, simple arithmetic ops take ~1ns per operation
    // We aim for ~10 million iterations to reach ~0.01s given loop simplicity
    i__1 = 10000000;  // 10 million iterations
}

// Ensure symbols are defined at file scope
doublereal *r__;
integer i__1;
integer i__;
doublereal safmn2;