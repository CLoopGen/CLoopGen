#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1 * 3; ++i__) {
    work[(i__ - 1) % i__1 + 1] += (real)(i__ % 7) * 0.1F;
}
}
