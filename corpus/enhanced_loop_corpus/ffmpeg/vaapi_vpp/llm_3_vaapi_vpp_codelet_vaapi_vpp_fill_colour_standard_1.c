#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_vacs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Simulate indirect access using an auxiliary index mapping
    // Assume 'indices' array contains valid indices within a logical data array
    int *indices = (int*)malloc(nb_vacs * sizeof(int));
    if (!indices) return;
    for (i = 0; i < nb_vacs; i++) {
        indices[i] = nb_vacs - i - 1; // reverse mapping
    }
    for (i = 0; i < nb_vacs; i++) {
        int idx = indices[i];
        // Simulated indirect access: e.g., data[idx] = data[idx] * 2;
        // No actual data array used to keep self-contained
    }
    free(indices);
}
