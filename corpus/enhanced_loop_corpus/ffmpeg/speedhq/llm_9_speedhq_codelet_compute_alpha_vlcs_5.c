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
for (i = 0; i < 128; ++i) {
    int temp1 = i * 4;
    int temp2 = i * 8;
    level_code[entry + 0] = temp1;
    level_code[entry + 1] = temp2;
    level_bits[entry + 0] = 9;
    level_bits[entry + 1] = 10;
    level_symbols[entry + 0] = i;
    level_symbols[entry + 1] = i + 128;
    entry += 2;
}
}
