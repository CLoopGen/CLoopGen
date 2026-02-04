#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern uint32_t scratch;
extern  uint8_t *buf_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with decreasing stride pattern
    size_t stride = 4;
    uint8_t *ptr = buf;

    // First pass: forward strided access (every 4th byte)
    for (; stride >= 1; stride--) {
        for (ptr = buf; ptr < buf_end; ptr += stride) {
            scratch ^= *ptr;
            if (ptr + stride >= buf_end) break;
        }
    }

    // Final sequential cleanup for any remaining unprocessed bytes
    for (ptr = buf; ptr < buf_end; ptr++) {
        scratch ^= *ptr;
    }
}
