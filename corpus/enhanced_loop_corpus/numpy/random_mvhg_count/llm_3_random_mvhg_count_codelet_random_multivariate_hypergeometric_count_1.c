#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t num_colors;
extern int64_t *colors;
extern size_t *choices;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary index array to shuffle the order in which `choices` is updated.
    // This simulates indirect or random access pattern based on precomputed indices.
    size_t total_elements = 0;
    for (size_t i = 0; i < num_colors; ++i) {
        total_elements += colors[i];
    }

    // Simulate precomputed permutation indices (using simple deterministic scrambling)
    size_t *permuted_index = (size_t*)malloc(total_elements * sizeof(size_t));
    if (!permuted_index) return; // Handle allocation failure

    for (size_t idx = 0; idx < total_elements; ++idx) {
        // Simple pseudo-random-like permutation using quadratic probing mod size
        permuted_index[idx] = (idx * idx + 3 * idx + 1) % total_elements;
    }

    for (size_t i = 0, k = 0; i < num_colors; ++i) {
        for (int64_t j = 0; j < colors[i]; ++j) {
            choices[permuted_index[k]] = i; // Write through permuted index
            ++k;
        }
    }

    free(permuted_index);
}
