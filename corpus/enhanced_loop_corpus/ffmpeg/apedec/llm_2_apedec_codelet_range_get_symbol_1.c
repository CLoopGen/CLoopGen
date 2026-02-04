#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t counts[];
extern int symbol;
extern int cf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (symbol = 0; symbol < 32767 && counts[symbol * 2 + 1] <= cf; symbol++)
        ;
}
