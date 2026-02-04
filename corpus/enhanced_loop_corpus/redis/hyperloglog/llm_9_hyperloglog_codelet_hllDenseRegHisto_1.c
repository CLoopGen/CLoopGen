#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *registers;
extern int *reghisto;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (1 << 15); j += 2) {
    for (int k = 0; k < 3; k++) {
        unsigned long idx = j + k;
        uint8_t *_p = (uint8_t *)registers;
        unsigned long _byte = idx * 6 / 8;
        unsigned long _fb = (idx * 6) & 7;
        unsigned long _fb8 = 8 - _fb;
        unsigned long b0 = _p[_byte];
        unsigned long b1 = _p[_byte + 1];
        unsigned long reg = ((b0 >> _fb) | (b1 << _fb8)) & 63;
        reghisto[reg]++;
    }
}
}
