#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, but adjust bounds accordingly)
    // Since original loop runs 5 times, we'll simulate stride of 2 by accessing x[0], x[2], x[4], x[6], x[8]
    // Extend logic to maintain meaningful computation with strided pattern
    for (i = 0; i < 10; i += 2) {
        if (i/2 < 5) {
            sum += (i/2 + 1.) * x[i];
        }
    }
}
