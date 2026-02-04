#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t rem[64];
extern int16_t basis[64];
extern int scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int acc = (1 << (16 - 6 - 1));
    for (i = 0; i < 8 * 8; i++) {
        int16_t product = basis[i] * scale;
        int16_t shift_val = (product + acc) >> (16 - 6);
        rem[i] += shift_val;
        // Introduce WAW and RAW dependency: each iteration depends on prior write to rem[i]
        // Also create intra-loop dependency by using updated rem in next iteration (loop-carried)
        if (i > 0) {
            rem[i] += rem[i-1] & 0xFF; // Add partial carry from previous result
        }
    }
}
