#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *dest;
extern int dest_index;
extern int count;
extern int src_pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with decreasing stride pattern
    // Access every second element first, then fill in the gaps (simulated strided write)
    int step = 2;
    int remainder;

    // First pass: write even-indexed elements (strided access)
    for (i = 0; i < count; i += step) {
        dest[dest_index + i] = dest[src_pos + i];
    }

    // Second pass: write odd-indexed elements
    for (remainder = 1; remainder < step; remainder++) {
        for (i = remainder; i < count; i += step) {
            dest[dest_index + i] = dest[src_pos + i];
        }
    }
}
