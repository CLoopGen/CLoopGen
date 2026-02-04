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
for (int j = 0; j < 2; j++) {
    int i = 0;
    while (i < 43) {
        b = 4 * (1 + (i > 10) + (i > 49));
        uint32_t condition_check = (shift >= b) && (((h & (4293918720U << (12 - b))) >> 20) == table[2 * i + 1]);
        if (condition_check && !(table[2 * i] >> 8 == 128U)) {
            *e0 = (*e0 & 16777215U) | (((12 + b - shift) | (64U << j)) << 22);
            if (j == 0) {
                *e1 = table[2 * i];
                shift -= b;
                h <<= b;
            } else {
                *e1 |= (unsigned int)table[2 * i] << 16;
            }
        }
        if (condition_check) break;
        i++;
    }
}
}
