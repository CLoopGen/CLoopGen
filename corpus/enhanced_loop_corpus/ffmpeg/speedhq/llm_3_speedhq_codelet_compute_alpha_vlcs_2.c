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
    // Variant 2: Indirect memory access using an index array
    // Access pattern is controlled via an indirection table
    int offsets[4] = {2, 0, 3, 1};  // arbitrary order for indirect access
    for (i = 0; i < 4; ++i) {
        int actual_index = entry + offsets[i];
        run_code[actual_index] = (i << 2) | 1;
        run_bits[actual_index] = 4;
        run_symbols[actual_index] = i + 1;
    }
    entry += 4;  // Advance entry by logical element count
}
