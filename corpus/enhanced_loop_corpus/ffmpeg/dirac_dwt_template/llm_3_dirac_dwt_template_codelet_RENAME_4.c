#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Access pattern determined by an auxiliary index array (gather-style access)
    int *data = (int*)malloc(w2 * sizeof(int));
    int *indices = (int*)malloc(w2 * sizeof(int));

    // Create reverse mapping for indirect access
    for (int i = 0; i < w2; i++) {
        indices[i] = w2 - 1 - i;
    }

    // Traverse using indirect addressing
    for (x = 0; x < w2; x++) {
        data[indices[x]] = x; // Indirect (reverse-order) write
    }

    free(data);
    free(indices);
}
