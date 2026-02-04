#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in a conceptual larger array)
    // Here, we simulate a strided access pattern by accessing steps with stride 2, but adjust loop bounds accordingly.
    // Since original array has 4 elements, we reduce iterations and double the index.
    for (c = 0; c < 2; c++)
        bits += steps[2 * c];
}
