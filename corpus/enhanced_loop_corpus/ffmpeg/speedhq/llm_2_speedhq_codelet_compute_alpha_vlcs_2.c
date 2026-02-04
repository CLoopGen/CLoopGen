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
    // Arrays are accessed at even indices only, simulating a strided pattern
    for (i = 0; i < 8; i += 2) {
        int idx = i / 2;  // map to 0..3
        run_code[entry + i] = (idx << 2) | 1;
        run_bits[entry + i] = 4;
        run_symbols[entry + i] = idx + 1;
    }
    entry += 8;  // Adjust entry to reflect total written elements
}
