#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with padding simulation
    // Simulate a strided access pattern by writing to every second element first, then filling gaps.
    // This splits the loop into two phases: even indices, then odd indices.
    int stride = 2;
    // First pass: even indices
    for (i = 0; i < width; i += stride)
        bits[i] = (value >> (width - i - 1)) & 1 ? '1' : '0';
    // Second pass: odd indices
    for (i = 1; i < width; i += stride)
        bits[i] = (value >> (width - i - 1)) & 1 ? '1' : '0';
}
