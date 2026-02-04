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
    int local_entry = entry;
    for (i = 0; i < 128; ++i) {
        run_code[local_entry] = (i << 3) | 7;
        run_bits[local_entry] = 10;
        run_symbols[local_entry] = i;
        local_entry++;
    }
    entry = local_entry;
}
