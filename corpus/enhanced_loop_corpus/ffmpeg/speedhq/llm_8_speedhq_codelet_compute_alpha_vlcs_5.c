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
for (i = 0; i < 512; ++i) {
    level_code[entry] = (i << 3) + (i << 1);
    level_bits[entry] = 12;
    level_symbols[entry] = (i & 255);
    ++entry;
}
}
