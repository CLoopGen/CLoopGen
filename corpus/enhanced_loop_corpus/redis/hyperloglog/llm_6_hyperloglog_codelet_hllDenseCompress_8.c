#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 14); i++) {
        uint8_t *_p = (uint8_t *)reg_dense;
        unsigned long _byte = i * 6 / 8;
        unsigned long _fb = (i * 6) & 7;
        unsigned long _fb8 = 8 - _fb;
        unsigned long _v = reg_raw[i];
        uint8_t temp_low = (_v << _fb) & 0xFF;
        uint8_t temp_high = _v >> _fb8;
        _p[_byte] = (_p[_byte] & ~(((1 << 6) - 1) << _fb)) | temp_low;
        if (_fb8 < 6) {
            _p[_byte + 1] = (_p[_byte + 1] & ~(((1 << 6) - 1) >> _fb8)) | temp_high;
        }
    }
}
