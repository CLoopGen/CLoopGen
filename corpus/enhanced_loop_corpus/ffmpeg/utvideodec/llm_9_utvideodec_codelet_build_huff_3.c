#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern int i;
extern HuffEntry he[256];
extern int last;
extern uint32_t codes[256];
extern uint8_t bits[256];
extern uint8_t syms[256];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce arithmetic operations by precomputing shift value and using additive update
uint32_t base_code = code;
for (i = last; i >= 0; i--) {
    uint8_t length = he[i].len;
    uint32_t shift = 32 - length;
    codes[i] = base_code >> shift;
    bits[i] = length;
    syms[i] = he[i].sym;
    // Replace expensive right shift in divisor with direct power-of-2 constant computation
    base_code += 1U << (31 - (length - 1)); // Equivalent to 2^31 / 2^(length-1)
}
code = base_code; // Update shared state at end
}
