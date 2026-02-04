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
    // Variant 1: Strided memory access pattern
    // Instead of sequential writes, write with a stride of 2 (wrapping if necessary)
    int stride = 2;
    for (i = 0; i < npes; ++i) {
        int target_index = (npes + sortsched[i]) % (npes * 2); // Ensure within bounds
        int strided_index = (target_index / stride) * stride;   // Snap to stride boundary
        if (strided_index >= npes * 2) strided_index -= stride;
        sortsched[strided_index] = sched[i];
    }
}
