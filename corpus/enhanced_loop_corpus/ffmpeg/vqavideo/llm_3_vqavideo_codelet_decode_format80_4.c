#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *dest;
extern int dest_index;
extern int count;
extern int src_pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via calculated indices)
    // Use a synthetic lookup pattern: reverse traversal order (indirect-like access)
    int *indices = (int*)alloca(count * sizeof(int));
    for (i = 0; i < count; i++) {
        indices[i] = count - 1 - i;  // reversed index mapping
    }
    for (i = 0; i < count; i++) {
        int idx = indices[i];
        dest[dest_index + idx] = dest[dest_index - src_pos + idx];
    }
}
