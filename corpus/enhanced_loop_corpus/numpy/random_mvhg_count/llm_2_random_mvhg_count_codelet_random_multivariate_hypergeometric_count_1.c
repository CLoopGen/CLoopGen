#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t num_colors;
extern int64_t *colors;
extern size_t *choices;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of writing sequentially to choices, write with a stride of 2,
    // wrapping around if necessary to avoid out-of-bounds (assuming sufficient buffer size).
    // This creates a non-consecutive access pattern.
    size_t total_elements = 0;
    for (size_t i = 0; i < num_colors; ++i) {
        total_elements += colors[i];
    }

    for (size_t i = 0, k = 0; i < num_colors; ++i) {
        for (int64_t j = 0; j < colors[i]; ++j) {
            size_t idx = (k * 2) % total_elements; // Strided access: every second position
            choices[idx] = i;
            ++k;
        }
    }
}
