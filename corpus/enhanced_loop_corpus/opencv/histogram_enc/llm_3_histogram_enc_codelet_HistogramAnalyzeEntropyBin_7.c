#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int histo_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Assume an external lookup array 'indices' maps to actual data locations
    extern int indices[];
    for (i = 0; i < histo_size; ++i) {
        int idx = indices[i]; // Indirect addressing
        // Simulate access using computed index
        // Example: temp = data[idx]; 
    }
}
