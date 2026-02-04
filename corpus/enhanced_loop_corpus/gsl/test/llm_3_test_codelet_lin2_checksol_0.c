#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Define a fixed index permutation to demonstrate indirect access
    size_t indices[] = {4, 0, 3, 1, 2}; // Reordered access: x[4], x[0], x[3], x[1], x[2]
    for (i = 0; i < 5; ++i) {
        sum += (i + 1.) * x[indices[i]];
    }
}
