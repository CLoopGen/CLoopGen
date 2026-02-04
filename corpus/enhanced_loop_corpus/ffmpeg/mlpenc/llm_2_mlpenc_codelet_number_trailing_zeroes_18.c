#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sample;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern simulation
    // Though no array is explicitly used, we simulate a strided memory-like probing via bit index jumps
    // Here we check every other bit first, then fill in if needed — effectively creating a strided access pattern
    int stride = 2;
    int found = 0;

    for (bits = 0; bits < 24 && !found; bits += stride) {
        if (sample & (1 << bits)) {
            // Found in strided pass; now backtrack to find the first set bit
            for (int j = bits - (stride - 1); j < bits; j++) {
                if (j >= 0 && (sample & (1 << j))) {
                    bits = j;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                bits = bits - (stride - 1);
                found = 1;
            }
        }
    }

    // If no bit was found in strided scan, fall back to linear from last point
    if (!found) {
        for (bits = (bits - stride) + 1; bits < 24; bits++) {
            if (sample & (1 << bits)) {
                found = 1;
                break;
            }
        }
        if (!found) bits = 24; // All bits checked, none set
    }
}
