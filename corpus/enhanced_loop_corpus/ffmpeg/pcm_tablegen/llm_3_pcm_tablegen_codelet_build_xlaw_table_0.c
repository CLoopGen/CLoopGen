#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Modify access pattern to use a strided access (stride of 2) instead of unit stride.
    // Simulates non-unit stride access which may affect cache performance and vectorization.

    for (; j < 8192; j += 2) {
        // Stride of 2: update two positions per iteration, but skip every other index
        if (j + 1 < 8192) {
            // Handle two indices at once to maintain progress toward loop bound
            linear_to_xlaw[8192 - j] = (127 ^ (mask ^ 128));
            linear_to_xlaw[8192 + j] = (127 ^ mask);
            linear_to_xlaw[8192 - (j+1)] = (127 ^ (mask ^ 128));
            linear_to_xlaw[8192 + (j+1)] = (127 ^ mask);
        } else {
            // Final iteration if 8192 is odd (though it's even, so this is safe)
            linear_to_xlaw[8192 - j] = (127 ^ (mask ^ 128));
            linear_to_xlaw[8192 + j] = (127 ^ mask);
        }
    }
    j = 8192; // Ensure loop exit condition is met
}
