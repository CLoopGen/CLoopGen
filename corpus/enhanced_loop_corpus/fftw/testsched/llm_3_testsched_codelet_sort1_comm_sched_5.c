#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sched;
extern int npes;
extern int *sortsched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic
    // Use pointers and indirect indexing through an offset array concept (simulated with arithmetic)
    // Introduces level of indirection by treating sortsched as an index map
    int *sched_ptr = sched;
    int *sortptr = sortsched;
    for (i = 0; i < npes; ++i) {
        int indirect_idx = sortptr[i];                    // Load index from sortsched
        int target_offset = npes + indirect_idx;          // Compute target location
        sortptr[target_offset] = *(sched_ptr + i);        // Store using pointer arithmetic
    }
}
