#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary index array to access left and right indirectly,
    // simulating irregular or pointer-chasing access patterns.
    // Here, we assume that the data flow involves indirect indexing through a permutation.
    int *index_map = (int*)malloc(ni * sizeof(int));
    if (!index_map) return; // Handle allocation failure

    // Create a simple reverse-indexing map for indirect access
    for (int idx = 0; idx < ni; idx++) {
        index_map[idx] = ni - 1 - idx;
    }

    for (i = 1; i < ni; ++i) {
        int mapped_i = index_map[i]; // Indirect access index
        int jj;
        for (jj = left[mapped_i]; jj <= right[mapped_i]; ++jj) {
            j++;
        }
    }

    free(index_map);
}
