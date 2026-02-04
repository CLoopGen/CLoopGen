#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 4; i++) {
        uint8_t *_p = (uint8_t *)reg_dense;
        unsigned long _byte = i * 3 / 4;
        unsigned long _fb = (i * 3) & 7;
        unsigned long b0 = _p[_byte];
        unsigned long b1 = _p[_byte + 1];
        unsigned long shifted_low = b0 >> _fb;
        unsigned long shifted_high = b1 << (8 - _fb);
        val = (shifted_low | shifted_high) & 63;
        reg_raw[2*i] = reg_raw[2*i] > val ? reg_raw[2*i] : val;
        reg_raw[2*i + 1] = reg_raw[2*i + 1] > val ? reg_raw[2*i + 1] : val;
    }
}
