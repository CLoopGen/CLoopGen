#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled stride simulation
    // Instead of strided access by 2, we traverse every element but simulate the original odd-index logic
    for (i = 1; i < buf_size; i++) {
        if (i % 2 == 1) {  // Only process odd indices to match original i += 2 behavior
            if (buf[i] == 119 || buf[i] == 11) {
                if (i > 0 && (buf[i] ^ buf[i - 1]) == (119 ^ 11)) {
                    i--;
                    break;
                } else if (i + 1 < buf_size && (buf[i] ^ buf[i + 1]) == (119 ^ 11)) {
                    break;
                }
            }
        }
    }
}
