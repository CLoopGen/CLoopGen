#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 2; i < (6 + 3); i += 2)
        equot[i] = 0;
}
