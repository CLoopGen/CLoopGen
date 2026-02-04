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
for (i = 0; i < 256; ++i) {
    int offset = i >> 1;
    run_code[entry] = (offset << 3) | 7;
    run_bits[entry] = (i & 1) ? 11 : 10;
    run_symbols[entry] = (i & 1) ? -offset : offset;
    ++entry;
}
}
