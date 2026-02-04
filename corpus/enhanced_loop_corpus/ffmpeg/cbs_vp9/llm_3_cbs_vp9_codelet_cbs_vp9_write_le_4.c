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
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use a base pointer and stride by 8 in each iteration to write in scattered locations
    char *base = bits;
    for (b = 0; b < width; b += 8) {
        char *p = base + b;
        for (i = 0; i < 8; i++) {
            p[i] = value >> (b + i) & 1 ? '1' : '0';
        }
    }
}
