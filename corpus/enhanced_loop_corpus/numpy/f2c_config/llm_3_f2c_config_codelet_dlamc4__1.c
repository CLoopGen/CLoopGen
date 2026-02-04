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
    // Variant 2: Memory Access Pattern Modification using indirect access via index mapping
    integer *indices = (integer *)malloc(i__1 * sizeof(integer));
    doublereal *buffer = (doublereal *)calloc(i__1, sizeof(doublereal));
    if (indices == NULL || buffer == NULL) {
        free(indices);
        free(buffer);
        return;
    }

    // Create reversed index mapping (indirect access)
    for (i__ = 1; i__ <= i__1; ++i__) {
        indices[i__ - 1] = i__1 - i__;  // reverse order
    }

    for (i__ = 1; i__ <= i__1; ++i__) {
        integer idx = indices[i__ - 1]; // indirect access
        buffer[idx] = b1;
        d1 += buffer[idx];
    }

    free(indices);
    free(buffer);
}
