#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int *indices = (int*)malloc((1 << 9) * sizeof(int));
    for (int j = 0; j < (1 << 9); j++) {
        indices[j] = (j * 5) % (1 << 10); // Generate non-consecutive, indirect indices
    }
    for (int j = 0; j < (1 << 9); j++) {
        int i = indices[j];
        if ((h_offsets[i] % 4) != 0)
            h_offsets[i] = (h_offsets[i] & ~3) + 4;
    }
    free(indices);
}
