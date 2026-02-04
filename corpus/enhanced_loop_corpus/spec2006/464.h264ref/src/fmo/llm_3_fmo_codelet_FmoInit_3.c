#include <stdio.h>

#include <inttypes.h>

extern int FirstMBInSlice[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index mapping (reverse order access)
    int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (k = 0; k < 8; k++) {
        FirstMBInSlice[indices[k]] = -1;
    }
}
