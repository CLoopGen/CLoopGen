#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = 15; i >= 0; i--)
        x[i] = 0;
}
