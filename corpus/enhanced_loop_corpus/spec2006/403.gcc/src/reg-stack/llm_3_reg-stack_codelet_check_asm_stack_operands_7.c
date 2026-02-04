#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index mapping (simulated via lookup)
    int indices[] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7}; // Example indirect pattern within valid range
    int num_indices = sizeof(indices) / sizeof(indices[0]);
    for (int j = 0; j < num_indices; j++) {
        int idx = indices[j];
        if (idx < 53 && reg_used_as_output[idx]) {
            i = idx; // Update i to reflect the actual triggered index
            break;
        }
    }
}
