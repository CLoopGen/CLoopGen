#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *linear_to_xlaw;
extern int mask;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride
    // Access memory locations with a stride of 2, processing two elements per iteration but skipping one each time
    // This changes the access pattern from dense to strided, still covering the same logical range
    int stride = 2;
    for (; j < 8192; j += stride) {
        // Apply values at strided positions symmetrically around 8192
        linear_to_xlaw[8192 - j] = (127 ^ (mask ^ 128));
        linear_to_xlaw[8192 + j] = (127 ^ mask);

        // Fill skipped index if within bounds (to maintain functional similarity)
        if (j + 1 < 8192) {
            linear_to_xlaw[8192 - (j + 1)] = (127 ^ (mask ^ 128));
            linear_to_xlaw[8192 + (j + 1)] = (127 ^ mask);
        }
    }
}
