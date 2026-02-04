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
    int temp_entry;
    temp_entry = entry;
    for (sign = 0; sign <= 1; ++sign) {
        level_code[temp_entry] = (sign << 1) | 1;
        level_bits[temp_entry] = 2;
        level_symbols[temp_entry] = sign ? -1 : 1;
        ++temp_entry;
        for (i = 0; i < 4; ++i) {
            level_code[temp_entry] = (i << 3) | (sign << 2) | 2;
            level_bits[temp_entry] = 5;
            level_symbols[temp_entry] = sign ? -(i + 2) : (i + 2);
            ++temp_entry;
        }
    }
    entry = temp_entry;
}
