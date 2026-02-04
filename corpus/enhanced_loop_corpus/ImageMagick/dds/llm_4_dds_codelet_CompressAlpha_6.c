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
    if (steps <= 1) return;
    for (i = 1; i < (ssize_t)steps; i++) {
        ssize_t weight_min = (ssize_t)steps - i;
        ssize_t weight_max = i;
        codes[i + 1] = (unsigned char)((weight_min * (ssize_t)min + weight_max * (ssize_t)max) / (ssize_t)steps);
    }
}
