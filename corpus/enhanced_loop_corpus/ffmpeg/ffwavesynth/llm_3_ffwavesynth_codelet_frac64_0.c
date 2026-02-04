#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t history[64];
    // Pre-initialize array to create predictable consecutive access later
    for (int j = 0; j < 64; j++) {
        history[j] = 0;
    }
    for (i = 63; i >= 0; i--) {
        // Consecutive memory access: write in reverse order with unit stride
        if (a >= (uint64_t)1 << 63 || a << 1 >= b) {
            r |= (uint64_t)1 << i;
            a = (a << 1) - b;
            history[i] = a; // Consecutive access in descending index order
        } else {
            a <<= 1;
            history[i] = a;
        }
    }
    // Dummy use to ensure memory operations are preserved
    r ^= history[63];
}
