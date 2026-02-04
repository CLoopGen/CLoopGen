#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with modulo-based permutation)
    int *index_map = (int*)malloc(ni * sizeof(int));
    for (int j = 0; j < ni; ++j)
        index_map[j] = (j * 3 + 1) % ni;  // Generate a pseudo-random permutation

    for (i = 0; i < ni; ++i) {
        int idx = index_map[i];
        left[idx] = q[idx];
    }

    free(index_map);
}
