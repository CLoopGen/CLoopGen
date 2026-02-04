#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *y;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Alters memory access pattern by traversing the array from high to low index
    for (i__ = i__1; i__ >= 1; --i__) {
        y[i__] = 0.F;
    }
}
