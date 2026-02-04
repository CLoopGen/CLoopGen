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
    level_code[entry] = (sign << 1) | 1;
    level_bits[entry] = 2;
    level_symbols[entry] = sign ? -1 : 1;
    ++entry;
    for (i = 0; i < 4; ++i) {
        level_code[entry] = (i << 3) | (sign << 2) | 2;
        level_bits[entry] = 5;
        level_symbols[entry] = sign ? -(i + 2) : (i + 2);
        ++entry;
    }
}

}
