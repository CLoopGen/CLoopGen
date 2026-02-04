#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern int last;
extern  int originalLast;
extern int i;
extern int nextend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the iteration order
    // and accessing output in a forward-stride manner.
    for (i = nextend - 1; i >= 0; i--)
        output[last + 1 + (nextend - 1 - i)] = output[originalLast - nextend + i];
}
