#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Access elements in a non-sequential order using an index lookup table
    int *array = (int*)malloc(w2 * sizeof(int));
    int *indices = (int*)malloc(w2 * sizeof(int));
    if (!array || !indices) {
        free(array); free(indices); return;
    }
    
    // Create an indirect permutation: reverse order indices
    for (int i = 0; i < w2; i++) {
        indices[i] = w2 - 1 - i;
    }
    
    for (x = 0; x < w2; x++) {
        int idx = indices[x];  // Indirect access
        array[idx] = x;
    }
    
    free(array); free(indices);
}
