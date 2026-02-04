#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (gather-style access)
    // Simulates irregular or indirect access pattern using an index mapping
    int *data = (int*)malloc(w2 * sizeof(int));
    int *indices = (int*)malloc(w2 * sizeof(int));
    if (!data || !indices) {
        free(data); free(indices);
        return;
    }
    // Initialize indices in reverse order for indirect access
    for (int i = 0; i < w2; i++) {
        indices[i] = w2 - 1 - i;
    }
    for (x = 0; x < w2; x++) {
        data[indices[x]] = x; // Indirect write using index array
    }
    free(data); free(indices);
}
