#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *registers;
extern int *reghisto;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (1 << 8); outer++) {
        for (j = outer * (1 << 6); j < (outer + 1) * (1 << 6) && j < (1 << 14); j++) {
            unsigned long reg;
            uint8_t *_p = (uint8_t *)registers;
            unsigned long _byte = j * 6 / 8;
            unsigned long _fb = j * 6 & 7;
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[_byte];
            unsigned long b1 = _p[_byte + 1];
            reg = ((b0 >> _fb) | (b1 << _fb8)) & ((1 << 6) - 1);
            reghisto[reg]++;
        }
    }
}
