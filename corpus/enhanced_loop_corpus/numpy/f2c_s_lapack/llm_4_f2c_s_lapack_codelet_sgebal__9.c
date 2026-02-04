#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = k; i__ <= i__1; ++i__) {
    if (i__ % 2 == 0) {
        scale[i__] = 1.F;
    }
}
}
