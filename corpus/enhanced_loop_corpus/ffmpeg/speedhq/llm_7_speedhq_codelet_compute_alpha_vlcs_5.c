#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t level_code[266];
extern uint8_t level_bits[266];
extern int16_t level_symbols[266];
extern int entry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; ++i) {
        level_symbols[entry] = i;
        level_code[entry] = level_symbols[entry] << 2;
        level_bits[entry] = 10;
        ++entry;
    }
}
