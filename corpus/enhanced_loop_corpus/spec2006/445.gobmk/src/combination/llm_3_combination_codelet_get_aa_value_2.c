#include <stdio.h>

#include <inttypes.h>

extern int aa_values[400];
extern int stones[361];
extern int k;
extern int num_stones;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive and Localized Memory Access via Reordering
    // Simulate consecutive access by assuming stones[] indices are reordered to improve locality.
    // Here we assume that stones[] contains scattered indices into aa_values[], 
    // and we process them in chunks to promote cache reuse.
    // We'll use a blocked (tiling-like) approach over the loop index.
    value = 0;
    int block_size = 16;
    for (int start = 0; start < num_stones; start += block_size) {
        int end = start + block_size;
        if (end > num_stones) end = num_stones;
        for (k = start; k < end; k++) {
            // Access remains indirect but is now localized within blocks
            value += aa_values[stones[k]];
        }
    }
}
