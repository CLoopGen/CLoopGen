#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t in_layout;
extern uint64_t out_layout;
extern int i;
extern double matrix[64][64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Precompute a list of valid indices where the bit condition holds,
    // then iterate over those indices indirectly.
    int indices[64];
    int count = 0;
    for (int temp_i = 0; temp_i < 64; temp_i++) {
        if (in_layout & out_layout & (1ULL << temp_i))
            indices[count++] = temp_i;
    }
    // Now use indirect access via the index array
    for (i = 0; i < count; i++) {
        int idx = indices[i];  // Indirect access to the target index
        matrix[idx][idx] = 1.;
    }
}
