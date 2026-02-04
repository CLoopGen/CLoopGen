#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Access elements based on an indirection array (gather access)
    // Assumes existence of an index map 'idx' that permutes access order
    extern size_t *idx; // assumed to be initialized elsewhere
    for (i = 0; i < src_size1; i++) {
        size_t actual_index = idx[i]; // indirect lookup
        // Use actual_index to access data (e.g., data[actual_index])
        // This introduces irregular memory access pattern
    }
}
