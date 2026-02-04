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
    for (int j = 0; j < 2; ++j) {
        for (i = 0; i < 4; ++i) {
            run_code[entry] = (i << 2) | 1;
            run_bits[entry] = 4;
            run_symbols[entry] = i + 1;
            ++entry;
        }
    }
}
