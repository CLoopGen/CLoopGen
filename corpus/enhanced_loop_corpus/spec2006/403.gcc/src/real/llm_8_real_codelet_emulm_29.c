#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (i = 2; i < 5; i++) {
        equot[i] = (unsigned short)((i * i + 3) % 256);
        equot[8 - i] = (unsigned short)((i * (i - 1)) % 256);
    }
}
