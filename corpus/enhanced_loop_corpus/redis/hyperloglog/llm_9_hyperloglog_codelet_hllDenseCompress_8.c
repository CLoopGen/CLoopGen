#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < (1 << 14); i += 2) {
    for (int j = 0; j < 2 && (i + j) < (1 << 14); j++) {
        int idx = i + j;
        uint8_t *_p = (uint8_t *)reg_dense;
        unsigned long _byte = idx * 6 / 8;
        unsigned long _fb = (idx * 6) & 7;
        unsigned long _fb8 = 8 - _fb;
        unsigned long _v = (reg_raw[idx]) & 0x3F;
        _p[_byte] &= ~((0x3F) << _fb);
        _p[_byte] |= _v << _fb;
        _p[_byte + 1] &= ~((0x3F) >> _fb8);
        _p[_byte + 1] |= _v >> _fb8;
    }
}
}
