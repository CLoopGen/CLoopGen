#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t table[];
extern uint32_t shift;
extern uint32_t *e0;
extern uint32_t *e1;
extern uint32_t b;
extern uint32_t h;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    for (int j = 0; j < 2; j++) {
        uint32_t local_b;
        uint32_t combined_mask = 64U << j;

        // Reverse iteration with strided access pattern: process every element but in reverse order
        for (int i = 42; i >= 0; i--) {
            local_b = 4 * (1 + (i > 10) + (i > 49));

            // Use strided access: still accessing table[2*i] and table[2*i+1], but now in reverse
            uint32_t val_even = table[2 * i];
            uint32_t val_odd = table[2 * i + 1];

            if (shift >= local_b && ((h & (4293918720U << (12 - local_b))) >> 20) == val_odd) {
                if (val_even >> 8 == 128U) {
                    return;
                } else {
                    *e0 = (*e0 & 16777215U) | (((12 + local_b - shift) | combined_mask) << 22);
                    if (j == 0) {
                        *e1 = val_even;
                        shift -= local_b;
                        h <<= local_b;
                    } else {
                        *e1 |= (unsigned int)val_even << 16;
                    }
                    break;
                }
            }
        }
    }
}
