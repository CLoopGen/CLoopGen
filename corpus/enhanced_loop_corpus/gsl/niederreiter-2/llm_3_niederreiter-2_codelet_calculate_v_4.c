#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int *indices = (int*)malloc(kj * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int i = 0; i < kj; i++) {
        indices[i] = i; // Populate index mapping
    }
    for (r = 0; r < kj; r++) {
        v[indices[r]] = 0;
    }
    free(indices);
}
