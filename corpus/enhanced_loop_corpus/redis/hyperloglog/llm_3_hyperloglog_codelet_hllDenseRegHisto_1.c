#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *registers;
extern int *reghisto;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access: process every 2nd element to create non-consecutive access
    for (j = 0; j < (1 << 14); j += 2) {
        unsigned long reg;
        uint8_t *_p = (uint8_t *)registers;
        // Modify index calculation to create strided logical access pattern
        int mapped_j = (j * 5) % (1 << 14); // Non-linear index mapping to alter access stride
        unsigned long _byte = mapped_j * 6 / 8;
        unsigned long _fb = (mapped_j * 6) & 7;
        unsigned long _fb8 = 8 - _fb;
        unsigned long b0 = _p[_byte];
        unsigned long b1 = _p[_byte + 1];
        reg = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;
        reghisto[reg]++;
    }
    // Final pass for odd indices to maintain full coverage
    for (j = 1; j < (1 << 14); j += 2) {
        unsigned long reg;
        uint8_t *_p = (uint8_t *)registers;
        unsigned long _byte = j * 6 / 8;
        unsigned long _fb = (j * 6) & 7;
        unsigned long _fb8 = 8 - _fb;
        unsigned long b0 = _p[_byte];
        unsigned long b1 = _p[_byte + 1];
        reg = ((b0 >> _fb) | (b1 << _fb8)) & 0x3F;
        reghisto[reg]++;
    }
}
