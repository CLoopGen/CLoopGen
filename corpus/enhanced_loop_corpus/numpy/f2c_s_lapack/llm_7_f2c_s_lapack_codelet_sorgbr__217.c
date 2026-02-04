#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 2; i__ <= i__1; ++i__) {
        a[i__ + a_dim1] = a[i__ - 1 + a_dim1]; // Introduce loop-carried RAW dependency
        a[i__ - 1 + a_dim1] = 0.F;             // Create WAR: write after previous read; shifts zeroing pattern
    }
    if (i__1 >= 2) {
        a[i__1 + a_dim1] = 0.F; // Final element fix-up to maintain semantic similarity
    }
}
