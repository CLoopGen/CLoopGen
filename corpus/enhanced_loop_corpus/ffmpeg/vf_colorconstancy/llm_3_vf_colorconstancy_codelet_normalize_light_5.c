#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic
    double *ptr = light;
    for (plane = 0; plane < 3; ++plane) {
        *(ptr++) = 1.;
    }
}
