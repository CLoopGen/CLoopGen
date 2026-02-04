#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = (1 << 14) - 64; i < (1 << 14); i += 2) {
    uint8_t *_p = (uint8_t *)reg_dense;
    unsigned long _byte = i * 6 >> 3;
    unsigned long _fb = (i * 6) & 7;
    unsigned long _fb8 = 8 - _fb;
    unsigned long _v = reg_raw[i];
    unsigned long _mask_low = ((1UL << 6) - 1) << _fb;
    unsigned long _mask_high = ((1UL << 6) - 1) >> _fb8;
    _p[_byte] = (_p[_byte] & ~_mask_low) | ((_v << _fb) & _mask_low);
    if (_fb8 < 6) {
        _p[_byte + 1] = (_p[_byte + 1] & ~_mask_high) | ((_v >> _fb8) & _mask_high);
    } else {
        _p[_byte + 1] &= ~((1UL << (6 - _fb8)) - 1);
        _p[_byte + 1] |= (_v >> _fb8) & ((1UL << (6 - _fb8)) - 1);
    }
}
}
