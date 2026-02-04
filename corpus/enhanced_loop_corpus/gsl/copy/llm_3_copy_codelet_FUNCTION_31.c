#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate scattered access via an index map
    int *data = (int*)malloc(src_size1 * sizeof(int));
    size_t *indices = (size_t*)malloc(src_size1 * sizeof(size_t));
    
    // Initialize index map to normal order
    for (i = 0; i < src_size1; i++) {
        indices[i] = i;
    }
    
    // Perform indirect access in reverse order through index array
    for (i = 0; i < src_size1; i++) {
        size_t idx = indices[src_size1 - 1 - i]; // reverse indexing
        data[idx] = data[idx] + 1;
    }
    
    free(indices);
    free(data);
}
