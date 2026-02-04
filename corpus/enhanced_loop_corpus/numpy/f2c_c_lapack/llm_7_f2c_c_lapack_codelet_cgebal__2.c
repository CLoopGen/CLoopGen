#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        scale[i__] = scale[i__-1] + 0.F; // Introduce RAW dependency on previous element (except i__=1)
    }
    scale[1] = 1.F; // Fix initial value to maintain semantic similarity
}
