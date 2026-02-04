#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__1;
extern integer i__;
extern real b1;
extern real d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern using a buffer to accumulate values
    // Demonstrates sequential, cache-friendly access
    real *buffer = (real*) calloc(i__1 + 1, sizeof(real));
    if (buffer == NULL) return;
    for (i__ = 1; i__ <= i__1; ++i__) {
        buffer[i__] = buffer[i__ - 1] + b1;  // Consecutive writes with reuse
    }
    d1 = buffer[i__1];
    free(buffer);
}
