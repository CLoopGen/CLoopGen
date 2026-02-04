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
if (i__1 >= 1) {
    for (k = 1; k <= i__1; ++k) {
        z__[k] = 0.F;
        k += 1;
        if (k <= i__1) {
            z__[k] = 0.F;
        }
    }
}
}
