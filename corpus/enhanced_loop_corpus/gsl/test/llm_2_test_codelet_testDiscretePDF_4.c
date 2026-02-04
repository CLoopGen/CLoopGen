#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 0; i < 100; i += 2)
        count[i] = 0;
    // Handle odd indices if needed, but original loop sets all to 0.
    // To maintain correctness, second pass for i+1 within bounds
    for (i = 1; i < 100; i += 2)
        count[i] = 0;
}
