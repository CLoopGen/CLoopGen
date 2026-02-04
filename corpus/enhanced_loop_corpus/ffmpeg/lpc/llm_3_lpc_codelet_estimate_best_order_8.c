#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ref;
extern int min_order;
extern int max_order;
extern int i;
extern int est;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array, simulating irregular access pattern
    int size = max_order - min_order + 1;
    int *indices = (int*)malloc(size * sizeof(int));
    if (!indices) return; // Handle allocation failure
    // Precompute reverse order indices for indirect access
    for (int j = 0; j < size; j++) {
        indices[j] = max_order - 1 - j;
    }
    est = 0; // Reset result
    for (int j = 0; j < size; j++) {
        i = indices[j];
        if (i >= min_order - 1 && ref[i] > 0.10000000000000001) {
            est = i + 1;
            break;
        }
    }
    free(indices);
}
