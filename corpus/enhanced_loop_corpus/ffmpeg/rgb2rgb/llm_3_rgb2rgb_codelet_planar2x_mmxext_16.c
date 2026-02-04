#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every second element in reverse order
    // This variant changes both access pattern (strided and reversed) and direction
    for (x = (srcWidth - 2) & ~1; x >= 0; x -= 2) {
        int idx = x;
        // Access with stride of 2 in source, still compute two interpolated outputs
        dst[2 * idx + 1] = (3 * src[idx] + src[idx + 1]) >> 2;
        dst[2 * idx + 2] = (src[idx] + 3 * src[idx + 1]) >> 2;

        // Handle intermediate step if needed (ensure correctness for odd steps)
        if (x > 0) {
            idx = x - 1;
            dst[2 * idx + 1] = (3 * src[idx] + src[idx + 1]) >> 2;
            dst[2 * idx + 2] = (src[idx] + 3 * src[idx + 1]) >> 2;
        }
    }
}
