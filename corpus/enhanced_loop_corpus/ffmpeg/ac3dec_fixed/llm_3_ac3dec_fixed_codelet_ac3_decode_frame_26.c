#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with dual-element processing
    // Process pairs of adjacent elements in sequence, unrolling the original stride-2 pattern
    for (i = 1; i < buf_size - 1; i += 1) {
        uint8_t val1 = buf[i];
        uint8_t val_prev = buf[i - 1];
        if (val1 == 119 || val1 == 11) {
            if ((val1 ^ val_prev) == (119 ^ 11)) {
                i--;
                break;
            }
            if (i + 1 < buf_size) {
                uint8_t val_next = buf[i + 1];
                if ((val1 ^ val_next) == (119 ^ 11)) {
                    break;
                }
            }
        }
    }
}
