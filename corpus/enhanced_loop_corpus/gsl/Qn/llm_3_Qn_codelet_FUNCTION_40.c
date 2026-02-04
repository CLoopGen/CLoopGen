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
    // Variant 2: Indirect memory access using an index remapping array
    // Simulate indirect access via a permutation table (e.g., reverse order access)
    int *index_map = (int*)malloc(ni * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create a reverse index mapping: access elements from end to start
    for (int j = 0; j < ni; ++j) {
        index_map[j] = ni - 1 - j;
    }

    for (i = 0; i < ni; ++i) {
        int mapped_i = index_map[i]; // Use remapped index
        left[mapped_i] = ni - mapped_i + 1;
        right[mapped_i] = (mapped_i <= h) ? ni : ni - (mapped_i - h);
    }

    free(index_map);
}
