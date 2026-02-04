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
    // Variant 2: Remove loop-carried dependencies entirely by unrolling and removing index mutation inside loop
    // Also eliminate RAW/WAR/WAW on 'entry' by computing final value directly
    int base_entry = entry;
    run_code[base_entry + 0] = (0 << 2) | 1;
    run_bits[base_entry + 0] = 4;
    run_symbols[base_entry + 0] = 1;

    run_code[base_entry + 1] = (1 << 2) | 1;
    run_bits[base_entry + 1] = 4;
    run_symbols[base_entry + 1] = 2;

    run_code[base_entry + 2] = (2 << 2) | 1;
    run_bits[base_entry + 2] = 4;
    run_symbols[base_entry + 2] = 3;

    run_code[base_entry + 3] = (3 << 2) | 1;
    run_bits[base_entry + 3] = 4;
    run_symbols[base_entry + 3] = 4;

    entry = base_entry + 4;  // Update only once after all writes
}
