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



void loop(){
for (int j = 0; j < 1; j++) {
    for (int i = 0; i < 86; i += 2) {
        uint32_t temp_b = 4;
        if (i > 10) temp_b += 4;
        if (i > 49) temp_b += 4;
        if (i > 69) temp_b += 4;
        if (shift >= temp_b && ((h & (4293918720U << (12 - temp_b))) >> 20) == table[i + 1]) {
            if (table[i] >> 8 == 128U) {
                return;
            } else {
                *e0 = (*e0 & 16777215U) | (((12 + temp_b - shift) | (64U << j)) << 22);
                *e1 = table[i];
                shift -= temp_b;
                h <<= temp_b;
                break;
            }
        }
        if (shift >= temp_b && ((h & (4293918720U << (12 - temp_b))) >> 20) == table[i + 3]) {
            if (table[i + 2] >> 8 == 128U) {
                return;
            } else {
                *e0 = (*e0 & 16777215U) | (((12 + temp_b - shift) | (64U << j)) << 22);
                *e1 |= (unsigned int)table[i + 2] << 16;
                shift -= temp_b;
                h <<= temp_b;
            }
        }
    }
}
}
