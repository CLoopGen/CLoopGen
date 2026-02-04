#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *registers;
extern int *reghisto;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (1 << 10); j++) {
        unsigned long reg1, reg2, reg3, reg4;
        // Unroll inner operations to simulate deeper effective iteration with multiple steps per loop
        // First virtual iteration
        {
            uint8_t *_p = (uint8_t *)registers;
            unsigned long _byte = j * 4 * 6 / 8;
            unsigned long _fb = (j * 4 * 6) & 7;
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[_byte];
            unsigned long b1 = _p[_byte + 1];
            reg1 = ((b0 >> _fb) | (b1 << _fb8)) & ((1 << 6) - 1);
        }
        // Second
        {
            uint8_t *_p = (uint8_t *)registers;
            unsigned long _byte = (j * 4 + 1) * 6 / 8;
            unsigned long _fb = ((j * 4 + 1) * 6) & 7;
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[_byte];
            unsigned long b1 = _p[_byte + 1];
            reg2 = ((b0 >> _fb) | (b1 << _fb8)) & ((1 << 6) - 1);
        }
        // Third
        {
            uint8_t *_p = (uint8_t *)registers;
            unsigned long _byte = (j * 4 + 2) * 6 / 8;
            unsigned long _fb = ((j * 4 + 2) * 6) & 7;
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[_byte];
            unsigned long b1 = _p[_byte + 1];
            reg3 = ((b0 >> _fb) | (b1 << _fb8)) & ((1 << 6) - 1);
        }
        // Fourth
        {
            uint8_t *_p = (uint8_t *)registers;
            unsigned long _byte = (j * 4 + 3) * 6 / 8;
            unsigned long _fb = ((j * 4 + 3) * 6) & 7;
            unsigned long _fb8 = 8 - _fb;
            unsigned long b0 = _p[_byte];
            unsigned long b1 = _p[_byte + 1];
            reg4 = ((b0 >> _fb) | (b1 << _fb8)) & ((1 << 6) - 1);
        }
        reghisto[reg1]++;
        reghisto[reg2]++;
        reghisto[reg3]++;
        reghisto[reg4]++;
    }
}
