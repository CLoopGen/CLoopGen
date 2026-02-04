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
for (i = 0; i < 64; ++i) {
    run_code[entry] = (i << 3) | 7;
    run_bits[entry] = 10;
    run_symbols[entry] = i;
    ++entry;

    run_code[entry] = ((i + 64) << 3) | 7;
    run_bits[entry] = 10;
    run_symbols[entry] = i + 64;
    ++entry;
}
}
