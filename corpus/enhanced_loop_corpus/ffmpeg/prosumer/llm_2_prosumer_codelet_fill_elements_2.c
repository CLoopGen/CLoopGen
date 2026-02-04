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
    // Variant 1: Consecutive memory access with precomputed indices
    uint32_t temp_table[86];
    for (int k = 0; k < 86; k++) {
        temp_table[k] = table[k];
    }

    for (int j = 0; j < 2; j++) {
        int base_shift = 64U << j;
        for (int i = 0; i < 43; i++) {
            uint32_t idx = 2 * i;
            b = 4 * (1 + (i > 10) + (i > 49));

            if (shift >= b && ((h & (4293918720U << (12 - b))) >> 20) == temp_table[idx + 1]) {
                if (temp_table[idx] >> 8 == 128U) {
                    return;
                } else {
                    *e0 = (*e0 & 16777215U) | (((12 + b - shift) | base_shift) << 22);
                    if (j == 0) {
                        *e1 = temp_table[idx];
                        shift -= b;
                        h <<= b;
                    } else {
                        *e1 |= (unsigned int)temp_table[idx] << 16;
                    }
                    break;
                }
            }
        }
    }
}
