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
    // Variant 2: Indirect memory access using an index array (simulated via precomputed indices)
    int indices[128];
    for (int temp_i = 0; temp_i < 128; ++temp_i) {
        indices[temp_i] = 127 - temp_i; // Reverse order access pattern
    }
    for (i = 0; i < 128; ++i) {
        int idx = indices[i]; // Indirect access through index remapping
        run_code[entry] = (idx << 3) | 7;
        run_bits[entry] = 10;
        run_symbols[entry] = idx;
        ++entry;
    }
}
