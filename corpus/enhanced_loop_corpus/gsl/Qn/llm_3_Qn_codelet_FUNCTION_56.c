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
    // Variant 2: Indirect memory access using an index map (reverse order traversal)
    int *index_map = (int*)malloc(ni * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create reverse index mapping: process elements from end to start
    for (int j = 0; j < ni; ++j) {
        index_map[j] = ni - 1 - j;
    }

    for (i = 0; i < ni; ++i) {
        int mapped_idx = index_map[i]; // Indirect access via mapping
        left[mapped_idx] = ni - mapped_idx + 1;
        right[mapped_idx] = (mapped_idx <= h) ? ni : ni - (mapped_idx - h);
    }

    free(index_map);
}
