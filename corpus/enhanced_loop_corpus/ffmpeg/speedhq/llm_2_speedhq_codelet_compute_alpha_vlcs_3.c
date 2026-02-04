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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 128; i += 2) {
        run_code[entry] = (i << 3) | 7;
        run_bits[entry] = 10;
        run_symbols[entry] = i;
        ++entry;
        
        if (i + 1 < 128) {
            run_code[entry] = ((i + 1) << 3) | 7;
            run_bits[entry] = 10;
            run_symbols[entry] = i + 1;
            ++entry;
        }
    }
}
