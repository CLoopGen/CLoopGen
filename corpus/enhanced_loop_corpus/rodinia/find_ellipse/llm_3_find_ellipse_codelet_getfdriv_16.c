#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    // Simulate indirect access by reversing the order of assignment through an auxiliary index
    for (i = 0; i < N - 1; i++) {
        int idx = (N - 2) - i;  // Reverse traversal index: indirect-like access pattern
        cindex[idx] = idx + 1;
    }
}
