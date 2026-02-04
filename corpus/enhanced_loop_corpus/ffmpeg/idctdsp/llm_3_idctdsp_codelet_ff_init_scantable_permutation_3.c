#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step of 8 (access every 8th element first, then offset)
    int base, step;
    int idx = 0;
    for (base = 0; base < 8; base++) {
        for (i = 0; i < 8; i++) {
            int pos = base + (i * 8);
            idct_permutation[idx++] = (pos & 56) | ((pos & 6) >> 1) | ((pos & 1) << 2);
        }
    }
}
