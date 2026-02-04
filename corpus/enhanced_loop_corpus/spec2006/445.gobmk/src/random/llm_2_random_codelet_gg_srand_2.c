#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[25];
extern unsigned int seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, wrapping around using modulo
    for (i = 0; i < 25; i++) {
        int index = (i * 2) % 25;  // Strided access: every second element
        x[index] = seed;
        seed *= 1313;
        seed += 88897;
    }
}
