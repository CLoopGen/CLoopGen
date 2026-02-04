#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *_p = (uint8_t *)reg_dense;
unsigned long _v_cache[32];
for (int j = 0; j < 32; j++) {
    int i = (1 << 14) - 32 + j;
    _v_cache[j] = reg_raw[i];
}
for (int j = 0; j < 32; j++) {
    int i = (1 << 14) - 32 + j;
    unsigned long _byte = i * 6 / 8;
    unsigned long _fb = (i * 6) & 7;
    unsigned long _fb8 = 8 - _fb;
    unsigned long _v = _v_cache[j];
    _p[_byte] &= ~(((1UL << 6) - 1) << _fb);
    _p[_byte] |= _v << _fb;
    if (_fb != 0) {
        _p[_byte + 1] &= ~(((1UL << 6) - 1) >> _fb8);
        _p[_byte + 1] |= _v >> _fb8;
    }
}
}
