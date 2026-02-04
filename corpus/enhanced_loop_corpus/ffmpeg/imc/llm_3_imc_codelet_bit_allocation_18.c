#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float lowest;
extern int low_indx;
extern float workT[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[32];
    for (int j = 0; j < 32; j++) {
        indices[j] = j;
    }
    // Simulate indirect access by accessing workT through permuted indices
    // Simple permutation: reverse order
    for (i = 0; i < 32; i++) {
        int idx = indices[31 - i]; // reverse traversal
        if (workT[idx] < lowest) {
            lowest = workT[idx];
            low_indx = idx;
        }
    }
}
