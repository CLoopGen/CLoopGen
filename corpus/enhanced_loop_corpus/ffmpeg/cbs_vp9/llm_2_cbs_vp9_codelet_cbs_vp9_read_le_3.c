#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern int b;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the loop order
    // This changes the access pattern from strided (b + i) to consecutive within inner loop
    for (i = 0; i < 8; i++)
        for (b = 0; b < width; b += 8)
            bits[b + i] = (value >> (b + i)) & 1 ? '1' : '0';
}
