#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k = 0;
    size_t r = 0;
    for (p = 0; p < size1; p++) {
        size_t temp = k + r; // Loop-carried dependence: k and r used across iterations
        r = temp + 1;
        k = r - p; // RAW: depends on updated r; loop-carried via k to next iteration
        size_t c = p; // Independent of prior computations in loop
    }
}
