#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t table[86]; // Size to cover 2*i+1 with i up to 42 -> max index 85
uint32_t shift = 12;
uint32_t *e0;
uint32_t *e1;
uint32_t b;
uint32_t h;

static uint32_t buffer_pool[2]; // Provide storage for e0 and e1 pointers

void init_vars() {
    // Initialize table with safe values to prevent early return and allow full loop execution
    for (int i = 0; i < 86; i++) {
        if (i % 2 == 0) {
            // Even indices: avoid 128U in high byte to prevent premature return
            table[i] = (63U << 8) | (i & 0xFF); 
        } else {
            // Odd indices: ensure condition ((h & mask) >> 20) != table[2*i+1] initially
            table[i] = i & 0xFFFF;
        }
    }

    // Initialize pointer targets
    e0 = &buffer_pool[0];
    e1 = &buffer_pool[1];
    
    // Initial values to ensure the loop runs through multiple iterations
    h = 4293918720U; // Matches the magic constant in condition
    shift = 12;      // Start high enough to enter the first condition
    
    // Ensure *e0 has defined state
    *e0 = 0;
    *e1 = 0;
}