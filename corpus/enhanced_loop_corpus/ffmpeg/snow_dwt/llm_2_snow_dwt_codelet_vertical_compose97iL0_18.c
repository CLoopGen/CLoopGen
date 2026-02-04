#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in the arrays, traversing with a step size of 2
    for (i = 0; i < width; i += 2)
        if (i < width)
            b1[i] += (1 * (b0[i] + b2[i]) + 4 * b1[i] + 8) >> 4;
}
