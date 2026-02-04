#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t zeroes;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant writes '0' to every second element first, then fills in the gaps
    for (i = 0; i < zeroes; i += 2)
        bits[i] = '0';
    for (i = 1; i < zeroes; i += 2)
        bits[i] = '0';
}
