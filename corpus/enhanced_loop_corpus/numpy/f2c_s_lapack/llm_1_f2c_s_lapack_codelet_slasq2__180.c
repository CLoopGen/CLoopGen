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
if (i__1 >= 2) {
    for (k = 2; k <= i__1; ++k) {
        for (integer level = 1; level <= 1; ++level) {
            z__[k] = z__[(k << 2) - 3];
        }
    }
}
}
