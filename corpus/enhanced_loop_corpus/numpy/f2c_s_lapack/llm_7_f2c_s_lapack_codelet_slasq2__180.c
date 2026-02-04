#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 2; k <= i__1; ++k) {
    real temp = z__[(k << 2) - 3];
    z__[k] = temp;
}
}
