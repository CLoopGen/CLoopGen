#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 32; row--;) {
        // Variant 1: Consecutive memory access by treating dst as a linear buffer
        // Instead of strided row jumps, write 8 consecutive bytes per iteration
        for (int offset = 0; offset < 8; ++offset) {
            dst[offset] = row ^ offset;
        }
        dst += 8; // Move forward by 8 bytes each row (consecutive block access)
    }
}
