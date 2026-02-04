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
    // Variant 2: Strided memory access pattern using a larger array with fixed stride
    const ptrdiff_t stride = 4;
    doublereal *buffer = (doublereal *)calloc(i__1 * stride, sizeof(doublereal));
    for (i__ = 1; i__ <= i__1; ++i__) {
        buffer[(i__ - 1) * stride] = b2;
        d2 += buffer[(i__ - 1) * stride];
    }
    free(buffer);
}
