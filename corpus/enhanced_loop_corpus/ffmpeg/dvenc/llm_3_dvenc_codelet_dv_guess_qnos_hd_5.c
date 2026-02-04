#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    int indices[5] = {4, 0, 3, 1, 2}; // Custom indirect access order
    for (i = 0; i < 5; i++) {
        int idx = indices[i]; // Access elements in shuffled order
        if (qlevels[idx] < qlevels[largest])
            largest = idx;
    }
}
