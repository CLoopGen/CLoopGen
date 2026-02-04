#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int channels;
extern  int32_t *samples;
extern int stride;
extern uint32_t bits[2];
extern int result;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by eliminating pointer arithmetic inside inner loop,
    // precomputing sample indices, and decreasing effective work via skipping every other channel.
    // Outer loop runs at reduced frequency with doubled step, increasing stride effect.

    int step_channels = (channels + 1) / 2; // Process only half the channels (every other)
    for (j = result - 1; j >= 0; j--) {
        int base_idx = (result - 1 - j) * stride; // Linearized offset based on j
        for (i = 0; i < step_channels; i++) {
            int src_idx = base_idx + (i * 2); // Access only even-indexed channels
            bits[i % 2] |= ((samples[src_idx]) & 1) << j; // Distribute across bits[0] and bits[1]
        }
    }
    // Update samples to reflect full advancement
    samples += result * stride;
}
