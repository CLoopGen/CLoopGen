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
for (i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
        int index = i * 16 + j;
        if (index < 256) {
            level_code[entry] = index << 2;
            level_bits[entry] = 10;
            level_symbols[entry] = index;
            ++entry;
        }
    }
}
}
