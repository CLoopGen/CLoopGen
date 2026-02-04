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
    // Variant 2: Indirect memory access using an index map
    // Simulate indirect access via an auxiliary index array (emulated with arithmetic)
    // Here we reverse the access order: process elements from end to start indirectly
    int *indices = (int*)malloc(npes * sizeof(int));
    if (!indices) return; // Handle malloc failure
    for (int j = 0; j < npes; ++j)
        indices[j] = npes - 1 - j; // reversed index map

    for (i = 0; i < npes; ++i) {
        int idx = indices[i]; // indirect indexing
        sched[idx] = sortsched[npes + idx];
    }

    free(indices);
}
