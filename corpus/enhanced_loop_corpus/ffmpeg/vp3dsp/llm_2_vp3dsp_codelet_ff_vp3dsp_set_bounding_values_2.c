#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (x = 0; x < filter_limit; x += 2) {
        if (x < filter_limit) {
            bounding_values[-x] = -x;
            bounding_values[x] = x;
        }
    }
}
