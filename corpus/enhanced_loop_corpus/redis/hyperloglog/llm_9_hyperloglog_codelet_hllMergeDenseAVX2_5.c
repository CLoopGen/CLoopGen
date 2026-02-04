#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int i = (1 << 14) - 12; i < (1 << 14) + 12; i++) {
        uint8_t *_p = (uint8_t *)reg_dense;
        unsigned long offset = i * 6;
        unsigned long _byte = offset / 8;
        unsigned long _fb = offset % 8;
        unsigned long _fb8 = (8 - _fb) & 7;
        unsigned long b0 = *(volatile uint8_t*)&_p[_byte];
        unsigned long b1 = *(volatile uint8_t*)&_p[_byte + 1];
        val = ((b0 >> _fb) | (b1 << _fb8)) & 63;
        if (reg_raw[i] < val) {
            reg_raw[i] = val;
        }
    }
}
