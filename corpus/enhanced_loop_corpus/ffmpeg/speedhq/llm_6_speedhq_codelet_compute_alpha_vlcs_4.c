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
    uint16_t temp_code;
    uint8_t temp_bits;
    int16_t temp_symbol;
    for (sign = 0; sign <= 1; ++sign) {
        temp_code = (sign << 1) | 1;
        temp_bits = 2;
        temp_symbol = sign ? -1 : 1;
        level_code[entry] = temp_code;
        level_bits[entry] = temp_bits;
        level_symbols[entry] = temp_symbol;
        ++entry;
        for (i = 0; i < 4; ++i) {
            temp_code = (i << 3) | (sign << 2) | 2;
            temp_bits = 5;
            temp_symbol = sign ? -(i + 2) : (i + 2);
            level_code[entry] = temp_code;
            level_bits[entry] = temp_bits;
            level_symbols[entry] = temp_symbol;
            ++entry;
        }
    }
}
