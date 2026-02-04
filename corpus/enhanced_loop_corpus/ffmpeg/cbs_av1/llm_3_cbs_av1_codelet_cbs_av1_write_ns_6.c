#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t w;
extern uint32_t v;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access pattern
    // Traverse the array from high to low index (reverse order), still consecutive
    for (i = w - 2; i >= 0; i--)
        bits[i] = ((v >> i) & 1) ? '1' : '0';
}
