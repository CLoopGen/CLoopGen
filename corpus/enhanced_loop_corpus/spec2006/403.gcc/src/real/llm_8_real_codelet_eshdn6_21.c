#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and extended trip count
    // Trip count increased from original 4 to 8, and added arithmetic operation in index calculation
    for (i = 1; i < 9; i++) {
        unsigned short temp = *(--x);
        *(--p) = temp + (temp >> 2);  // Additional arithmetic: add shifted value
    }
}
