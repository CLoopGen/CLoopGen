#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse iteration
    // Instead of accessing bits in increasing index order based on left-shifted bit position,
    // we reverse the loop to write from high to low index, still maintaining correctness.
    for (i = width - 1; i >= 0; i--)
        bits[width - i - 1] = (value >> i) & 1 ? '1' : '0';
}
