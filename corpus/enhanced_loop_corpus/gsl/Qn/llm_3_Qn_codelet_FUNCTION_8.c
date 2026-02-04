#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reversed order traversal)
    // This creates a non-linear access pattern by iterating from end to start
    int *index_map = (int*)malloc(ni * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create a reverse index mapping: [ni-1, ni-2, ..., 0]
    for (int temp_i = 0; temp_i < ni; ++temp_i) {
        index_map[temp_i] = ni - 1 - temp_i;
    }

    for (int temp_i = 0; temp_i < ni; ++temp_i) {
        int idx = index_map[temp_i]; // Indirect access via mapped index
        left[idx] = ni - idx + 1;
        right[idx] = (idx <= h) ? ni : ni - (idx - h);
    }

    free(index_map);
}
