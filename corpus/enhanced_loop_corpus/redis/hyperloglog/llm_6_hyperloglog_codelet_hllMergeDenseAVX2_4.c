#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint8_t temp_val[8];
    for (int i = 0; i < 8; i++) {
        uint8_t *_p = (uint8_t *)reg_dense;
        unsigned long _byte = i * 6 / 8;
        unsigned long _fb = i * 6 & 7;
        unsigned long _fb8 = 8 - _fb;
        unsigned long b0 = _p[_byte];
        unsigned long b1 = _p[_byte + 1];
        temp_val[i] = ((b0 >> _fb) | (b1 << _fb8)) & ((1 << 6) - 1);
    }
    for (int i = 0; i < 8; i++) {
        reg_raw[i] = (reg_raw[i] > temp_val[i]) ? reg_raw[i] : temp_val[i];
    }
}
