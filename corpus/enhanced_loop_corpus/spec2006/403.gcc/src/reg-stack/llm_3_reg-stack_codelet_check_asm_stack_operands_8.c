#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char implicitly_dies[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using a local index array (indirect addressing via precomputed indices)
    int indices[] = {8,9,10,11,12,13,14}; // Precomputed consecutive indices
    int size = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < size; i++) {
        if (!implicitly_dies[indices[i]])
            break;
    }
}
