#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive (sequential) access
    // We introduce a sequential buffer to record each subtraction step, demonstrating
    // a coalesced, consecutive memory access pattern, commonly optimized in modern CPUs.
    // This maintains the original control flow but enhances memory interaction.

    double temp = normalized_degrees;
    double trace[500];  // Buffer for consecutive writes
    size_t pos = 0;
    rotations = 0;

    for (; temp > 45.; rotations++) {
        // Consecutive memory write - optimal cache usage
        if (pos < 500) {
            trace[pos++] = temp;
        }
        temp -= 90.;
    }
    normalized_degrees = temp;
}
