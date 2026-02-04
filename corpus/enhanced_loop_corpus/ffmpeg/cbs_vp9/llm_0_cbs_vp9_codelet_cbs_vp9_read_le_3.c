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
    for (b = 0; b < width; b += 8)
        for (int j = 7; j >= 0; j--)
            bits[b + (7 - j)] = (value >> (b + (7 - j))) & 1 ? '1' : '0';
}
