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
    // Variant 1: Consecutive Memory Access with Reordered Fields
    // Instead of writing one field across multiple arrays per iteration,
    // we restructure to write all fields for a given entry consecutively,
    // improving spatial locality and cache behavior.

    uint16_t code_temp;
    uint8_t bits_temp;
    int16_t symbols_temp;

    for (sign = 0; sign <= 1; ++sign) {
        // First block: two entries with simple codes
        code_temp = (sign << 1) | 1;
        bits_temp = 2;
        symbols_temp = sign ? -1 : 1;

        level_code[entry] = code_temp;
        level_bits[entry] = bits_temp;
        level_symbols[entry] = symbols_temp;
        ++entry;

        // Second block: four entries with increasing i
        for (i = 0; i < 4; ++i) {
            code_temp = (i << 3) | (sign << 2) | 2;
            bits_temp = 5;
            symbols_temp = sign ? -(i + 2) : (i + 2);

            level_code[entry] = code_temp;
            level_bits[entry] = bits_temp;
            level_symbols[entry] = symbols_temp;
            ++entry;
        }
    }
}
