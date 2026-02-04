#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern unsigned long r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive array access
    // Introduce a buffer to simulate consecutive memory writes during each iteration,
    // mimicking a more cache-friendly access pattern, while preserving loop count via bits.

    volatile unsigned long buffer[8]; // Local buffer for consecutive access
    size_t i;

    for (bits = 0; r > 0; ++bits) {
        // Perform consecutive writes to improve spatial locality
        for (i = 0; i < 8; ++i) {
            buffer[i] = r ^ (1UL << i); // Modify based on bit position
        }
        r >>= 1;
    }
}
