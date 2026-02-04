#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (access arrays from end to start)
    for (i = width - 1; i >= 0; i--)
        b1[i] -= (unsigned int)((int)(b0[i] + (unsigned int)b2[i] + 2) >> 2);
}
