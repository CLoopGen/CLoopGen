#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulate indirect access by reversing the order of iteration and accessing elements indirectly
    for (j = 0; j < Nc; j++) {
        long idx = Nc - 1 - j; // Reverse access pattern: indirect-like indexing
        jW[idx] = idx - 1;
        jE[idx] = idx + 1;
    }
}
