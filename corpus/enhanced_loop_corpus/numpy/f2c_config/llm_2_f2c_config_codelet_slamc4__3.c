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
    // Variant 1: Strided memory access pattern simulation using array with stride of 2
    // We simulate an array-like access with stride to demonstrate memory access modification
    real *array = (real*) malloc(sizeof(real) * (i__1 * 2));
    if (array == NULL) return;
    for (i__ = 1; i__ <= i__1; ++i__) {
        array[i__ * 2] += b1;  // Strided access: every 2nd index
    }
    d1 = array[i__1 * 2];
    free(array);
}
