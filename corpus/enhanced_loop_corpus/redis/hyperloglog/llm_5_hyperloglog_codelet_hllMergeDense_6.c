#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 14); i++) {
        uint8_t *_p = (uint8_t *)reg_dense;
        unsigned long _byte = i * 6 / 8;
        unsigned long _fb = i * 6 & 7;

        // Introduce early skip condition based on index parity to alter control flow
        if ((i & 1) == 0) {
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[_byte];
            unsigned long b1 = _p[_byte + 1];
            val = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;
            reg_raw[i] = reg_raw[i] > val ? val : reg_raw[i];
        } else {
            // Recompute with adjusted byte access for odd indices
            unsigned long alt_byte = (i * 5) / 8;
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[alt_byte];
            unsigned long b1 = _p[alt_byte + 1];
            val = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;
            if (val > reg_raw[i]) {
                reg_raw[i] = val;
            }
        }
    }
}
