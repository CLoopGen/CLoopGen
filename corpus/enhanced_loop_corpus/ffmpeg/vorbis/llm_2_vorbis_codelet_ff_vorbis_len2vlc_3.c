#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int i;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = p; (i < num) && (bits[i] == 0); i += 2)
        ;
}
