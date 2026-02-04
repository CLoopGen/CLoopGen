#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t run_code[134];
extern uint8_t run_bits[134];
extern int16_t run_symbols[134];
extern int entry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    for (int j = 0; j < 8; ++j) {
        int index = i * 8 + j;
        run_code[entry] = (index << 3) | 7;
        run_bits[entry] = 10;
        run_symbols[entry] = index;
        ++entry;
    }
}
}
