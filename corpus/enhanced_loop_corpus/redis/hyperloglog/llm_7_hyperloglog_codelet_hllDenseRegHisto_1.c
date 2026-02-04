#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *registers;
extern int *reghisto;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
unsigned long temp_reg = 0;
for (j = 0; j < (1 << 14); j++) {
    uint8_t *_p = (uint8_t *)registers;
    unsigned long _byte = j * 6 / 8;
    unsigned long _fb = (j ^ temp_reg) & 7;
    unsigned long _fb8 = 8 - _fb;
    unsigned long b0 = _p[_byte];
    unsigned long b1 = _p[_byte + 1];
    unsigned long reg = ((b0 >> _fb) | (b1 << _fb8)) & 63;
    temp_reg = reg; 
    reghisto[reg]++;
}
}
