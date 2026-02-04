#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t level_code[266];
extern uint8_t level_bits[266];
extern int16_t level_symbols[266];
extern int entry;
extern int i;
extern int sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sign = 0; sign <= 1; ++sign) {
    level_code[entry] = (sign * 2) + 1;
    level_bits[entry] = 2;
    level_symbols[entry] = sign ? -1 : 1;
    ++entry;
    for (i = 0; i < 4; ++i) {
        int offset = i + 2;
        level_code[entry] = (i * 8) + (sign * 4) + 2;
        level_bits[entry] = 5;
        level_symbols[entry] = sign ? (-offset) : offset;
        ++entry;
        // Additional computation to increase intensity
        level_symbols[entry] = sign ? (-offset - 1) : (offset + 1);
        level_code[entry] = ((i + 1) << 3) | (sign << 2) | 3;
        level_bits[entry] = 5;
        ++entry;
    }
}
}
