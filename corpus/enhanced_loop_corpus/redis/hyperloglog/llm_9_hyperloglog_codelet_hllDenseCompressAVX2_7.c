#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = (1 << 13); i < (1 << 14); i++) {
    uint8_t *_p = (uint8_t *)reg_dense;
    unsigned long _shift = i * 6;
    unsigned long _byte = _shift / 8;
    unsigned long _bit_offset = _shift % 8;
    unsigned long _value = reg_raw[i];
    unsigned long _high_shift = 8 - _bit_offset;

    uint8_t _low_byte_update = (_value << _bit_offset);
    uint8_t _high_byte_update = (_value >> _high_shift);

    uint8_t _low_mask = (0x3F << _bit_offset) & 0xFF;
    uint8_t _high_mask = (0x3F >> _high_shift) & 0xFF;

    _p[_byte]   = (_p[_byte] & ~_low_mask) | _low_byte_update;
    _p[_byte+1] = (_p[_byte+1] & ~_high_mask) | _high_byte_update;
}
}
