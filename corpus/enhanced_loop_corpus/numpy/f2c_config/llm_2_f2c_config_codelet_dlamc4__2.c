#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer i__;
extern doublereal b2;
extern doublereal d2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using array with unit stride
    doublereal *array = (doublereal *)malloc(i__1 * sizeof(doublereal));
    for (i__ = 0; i__ < i__1; ++i__) {
        array[i__] = b2;
        d2 += array[i__];
    }
    free(array);
}
