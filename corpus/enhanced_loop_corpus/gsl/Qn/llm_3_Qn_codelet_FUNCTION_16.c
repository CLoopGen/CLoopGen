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
    // Variant 2: Indirect memory access using an index map
    // Use a precomputed indirect access pattern via an auxiliary index array
    // Since we cannot modify function signature, simulate static index remapping
    int *idx_map = (int*)malloc(ni * sizeof(int));
    if (!idx_map) return; // Handle allocation failure

    // Create a reversed access order: access from end to start
    for (int temp_i = 0; temp_i < ni; ++temp_i) {
        idx_map[temp_i] = ni - 1 - temp_i;
    }

    for (i = 0; i < ni; ++i) {
        int mapped_i = idx_map[i]; // Indirect access index
        left[mapped_i] = ni - mapped_i + 1;
        right[mapped_i] = (mapped_i <= h) ? ni : ni - (mapped_i - h);
    }

    free(idx_map);
}
