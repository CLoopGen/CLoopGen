#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t min;
extern  size_t max;
extern  size_t steps;
extern unsigned char codes[8];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t accumulator = (ssize_t)min;
    ssize_t step_inc = ((ssize_t)max - (ssize_t)min) / (ssize_t)steps;
    codes[1] = (unsigned char)(accumulator);
    for (i = 1; i < (ssize_t)steps; i++) {
        accumulator += step_inc;
        codes[i + 1] = (unsigned char)accumulator;
    }
}
