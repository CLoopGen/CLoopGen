#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *speech;
extern int subframe_size;
extern int temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from last to first element)
    for (i = subframe_size - 1; i >= 0; i--)
        speech[i] = (speech[i] * temp + 16384) >> 15;
}
