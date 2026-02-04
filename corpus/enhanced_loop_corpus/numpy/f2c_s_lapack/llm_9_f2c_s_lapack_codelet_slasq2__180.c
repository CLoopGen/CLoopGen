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
    // Variant 2: Reduced computational intensity with increased trip count and simplified access pattern
    for (k = 1; k <= i__1 * 2; ++k) {
        if (k % 2 == 0) {
            z__[k >> 1] = z__[k];
        }
    }
}
