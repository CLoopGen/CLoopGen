#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the order and using sequential writes
    FFTSample *base = tab + m / 2 - 1;
    for (int i = 1; i < m / 4; i++)
        base[-i] = tab[i];
}
