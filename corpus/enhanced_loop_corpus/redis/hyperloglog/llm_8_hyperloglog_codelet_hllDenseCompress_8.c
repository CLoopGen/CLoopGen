#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < (1 << 13); i++) {
    uint8_t *_p = (uint8_t *)reg_dense;
    unsigned long _byte = i * 6 / 8;
    unsigned long _fb = (i * 6) & 7;
    unsigned long _fb8 = 8 - _fb;
    unsigned long _v = reg_raw[i] & 0x3F;
    _p[_byte] &= ~((0x3F) << _fb);
    _p[_byte] |= _v << _fb;
    if (_fb8 < 6) {
        _p[_byte + 1] &= ~((0x3F) >> _fb8);
        _p[_byte + 1] |= _v >> _fb8;
    }
}
}
