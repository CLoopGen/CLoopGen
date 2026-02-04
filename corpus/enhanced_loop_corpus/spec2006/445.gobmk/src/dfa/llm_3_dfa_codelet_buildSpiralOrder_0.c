#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int size = 21 * 4 * 21 * 4;
    for (ii = 0; ii < size; ii++) {
        int idx = (ii * 17) % size;  // Pseudo-random indirect indexing using modular arithmetic
        mark[idx] = 1;
    }
}
