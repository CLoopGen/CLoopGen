#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer i__;
extern doublereal b1;
extern doublereal d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern (simulated with array)
    doublereal *array = (doublereal *)calloc(i__1 * 2, sizeof(doublereal)); // Allocate space with padding for stride
    if (array == NULL) return;
    
    for (i__ = 1; i__ <= i__1; ++i__) {
        // Stride of 2: accessing every second element
        array[(i__ - 1) * 2] = b1;
        d1 += array[(i__ - 1) * 2];
    }
    
    free(array);
}
