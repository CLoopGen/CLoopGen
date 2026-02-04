#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Create a local index array that defines a custom access order (reverse even indices first, then odd)
    size_t indices[4] = {4, 2, 3, 1};  // Custom indirect access order for i from 1 to 4
    for (i = 0; i < 4; i++) {
        size_t idx = indices[i];
        hprev[idx] = hprev[idx - 1];
        ordprev[idx] = ordprev[idx - 1];
    }
}
