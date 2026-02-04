#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern double *squares;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with positive stride
    for (i = (-255); i <= 255; i += 2) {
        squares[i] = (double)i * (double)i;
    }
    // Fill in the odd indices in a second pass to maintain correctness
    for (i = (-254); i <= 254; i += 2) {
        squares[i] = (double)i * (double)i;
    }
}
