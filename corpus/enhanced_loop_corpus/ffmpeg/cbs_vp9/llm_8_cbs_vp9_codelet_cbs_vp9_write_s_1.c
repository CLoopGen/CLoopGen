#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t magnitude;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width && i < 32; i++) {
        uint32_t shift = width - i - 1;
        uint32_t masked = magnitude >> shift;
        bits[i] = (masked & 1) ? '1' : '0';
    }
    bits[i] = '\0'; // Null-terminate the string if within bounds
}
