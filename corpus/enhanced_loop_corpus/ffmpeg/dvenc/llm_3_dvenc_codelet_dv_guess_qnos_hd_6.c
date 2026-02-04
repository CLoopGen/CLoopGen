#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_qlevel[5];
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to change access pattern
    // Define a fixed indirect access order: e.g., reverse order via lookup indices
    int idx[5] = {4, 3, 2, 1, 0}; // reverse traversal order
    for (i = 0; i < 5; i++) {
        int j = idx[i]; // indirect access through index remapping
        if (qlevels[j] > min_qlevel[j] && qlevels[j] > qlevels[largest])
            largest = j;
    }
}
