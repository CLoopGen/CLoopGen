#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (j = i__1; j >= 1; --j) {
        psi += z__[j] * z__[j] / delta[j];
    }
}
