#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to shuffle access order
    int indices[7];
    for (int i = 0; i < 7; i++) {
        indices[i] = i;
    }
    // Shuffle indices to create non-sequential access (e.g., reverse order)
    for (k = 0; k < 7; k++) {
        int idx = indices[6 - k]; // Reverse traversal
        a_work[idx + 1] = a_work[idx] + bd_sequence[idx + 1];
    }
}
