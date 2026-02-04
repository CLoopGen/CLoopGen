#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided access pattern using a fixed stride over reg_dense with manual bit extraction
    // Simulate a more scattered but predictable access by changing index computation
    for (int i = 0; i < 8; i++) {
        // Use a non-linear but deterministic byte index to simulate strided behavior
        unsigned long _byte = (i * 5) / 8;  // Different multiplier to change access stride
        unsigned long _fb = (i * 5) & 7;
        unsigned long _fb8 = 8 - _fb;
        uint8_t *ptr = (uint8_t *)reg_dense;
        unsigned long b0 = ptr[_byte];
        unsigned long b1 = ptr[_byte + 1];
        val = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;
        reg_raw[i] = (reg_raw[i] > val) ? reg_raw[i] : val;
    }
}
