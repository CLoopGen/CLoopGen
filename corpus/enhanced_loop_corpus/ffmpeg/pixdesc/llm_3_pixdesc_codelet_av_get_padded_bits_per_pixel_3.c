#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int c;
extern int bits;
extern int steps[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Instead of direct sequential access, use an explicit index array to access steps indirectly
    int indices[4] = {3, 1, 0, 2};  // Define custom access order
    for (c = 0; c < 4; c++) {
        bits += steps[indices[c]];  // Access steps in shuffled order: 3,1,0,2
    }
}
