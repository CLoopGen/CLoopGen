#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an auxiliary index array to access elements in non-sequential order
    // Assume 'indices' is an externally defined array of integer indices
    extern int *indices;
    for (i = n4; i < n2; i++) {
        int actual_index = indices[i]; // Indirect access using index mapping
        // Simulated access using actual_index (e.g., arr[actual_index])
    }
}
