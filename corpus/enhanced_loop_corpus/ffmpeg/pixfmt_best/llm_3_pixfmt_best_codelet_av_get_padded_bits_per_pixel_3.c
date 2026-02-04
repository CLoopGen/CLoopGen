#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Define a fixed indirect access pattern via indices to demonstrate non-sequential access.
    int indices[] = {3, 1, 2, 0}; // Custom access order: reverse-like with swap
    for (c = 0; c < 4; c++)
        bits += steps[indices[c]];
}
