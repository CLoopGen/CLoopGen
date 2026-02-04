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
    // Variant 1: Consecutive memory access by reordering loops (loop interchange)
    // Outer loop now iterates over the 8-bit chunks, inner over width in strides of 8
    for (i = 0; i < 8; i++)
        for (b = 0; b < width; b += 8)
            bits[b + i] = value >> (b + i) & 1 ? '1' : '0';
}
