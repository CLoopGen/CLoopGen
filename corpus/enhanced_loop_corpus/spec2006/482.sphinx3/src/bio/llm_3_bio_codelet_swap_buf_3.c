#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (processing array from end to start)
    for (i = n_el - 1; i >= 0; i--)
        *(buf16 + i) = ((255 & (*(buf16 + i)) >> 8) | (65280 & (*(buf16 + i)) << 8));
}
