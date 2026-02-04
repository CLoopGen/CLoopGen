#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;
extern int current_pass;
extern int has_anything_changed;
extern uint8_t *current_pixel0;
extern uint8_t *current_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Pointer-Based Access with Local Buffer Simulation
    // Flatten the inner loop into a linear scan with explicit offset calculation.
    // Use a single loop over all valid pixels (excluding borders), accessing neighbors via fixed offsets.
    // This improves predictability and enables potential vectorization.
    int total_inner_pixels = (h - 2) * (w - 2);
    uint8_t* base = current_pixel0 + linesize + 1; // Start at (1,1)
    const int right_offset = 1;
    const int left_offset = -1;
    const int down_offset = linesize;
    const int up_offset = -linesize;
    has_anything_changed = 0;

    for (int i = 0; i < total_inner_pixels; i++) {
        uint8_t* center = base + (i / (w - 2)) * linesize + (i % (w - 2));
        if (*center >= current_pass && 
            *(center + right_offset) >= current_pass && 
            *(center + left_offset) >= current_pass && 
            *(center + down_offset) >= current_pass && 
            *(center + up_offset) >= current_pass) {
            (*center)++;
            has_anything_changed = 1;
        }
    }
}
